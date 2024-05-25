class Solution {
public:
    int minimumsum(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(i >= dp.size() || j >= dp[0].size())return 10000;
        if(dp[i][j] != -1)return dp[i][j];

        dp[i][j] = min(grid[i][j] + minimumsum(i + 1,j,dp,grid), grid[i][j] + minimumsum(i,j+1,dp,grid));

        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        return minimumsum(0,0,dp,grid);
    }
};