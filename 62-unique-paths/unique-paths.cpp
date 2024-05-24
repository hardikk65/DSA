class Solution {
public:
    int total_paths(int i, int j, vector<vector<int>> &dp){
        if(dp[i][j] != 0)return dp[i][j];

        dp[i][j] = total_paths(i + 1,j,dp) + total_paths(i,j + 1,dp);

        return dp[i][j];
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int> (n));
        for(int i = 0;i < n;i++){
            dp[m - 1][i] = 1;
        }
        for(int j = 0;j < m;j++){
            dp[j][n - 1] = 1;
        }

        return total_paths(0,0,dp);
        
    }
};