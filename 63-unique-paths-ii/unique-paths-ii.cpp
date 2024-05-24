class Solution {
public:
    long long int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector< long long int>> dp(m,vector<long long int>(n));

        if(obstacleGrid[m - 1][n - 1] == 1)return 0;
        dp[m - 1][n - 1] = 1;

        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                if(i == m - 1 && j == n - 1)continue;
                else if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == m - 1){
                    dp[i][j] = dp[i][j + 1];
                }
                else if(j == n - 1){
                    dp[i][j] = dp[i + 1][j];
                }
                else{
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};