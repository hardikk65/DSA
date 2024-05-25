class Solution {
public:

    int answer(int index, int row,vector<vector<int>> &dp,vector<vector<int>> &triangle){
        if(dp[row][index] != -1*pow(10,4) - 1)return dp[row][index];

        dp[row][index] = min(triangle[row][index] + answer(index,row + 1,dp,triangle),triangle[row][index] + answer(index + 1,row + 1,dp,triangle));

        return dp[row][index];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp;

        for(int i = 0;i < triangle.size();i++){
            dp.push_back(vector<int> (triangle[i].size(),-1*pow(10,4) - 1));
        }
        for(int i = 0;i < triangle[m - 1].size();i++){
            dp[m - 1][i] = triangle[m - 1][i];
        }
    
        return answer(0,0,dp,triangle);

        
    }
};