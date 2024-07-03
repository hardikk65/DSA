class Solution {
public:
    int f(int leftamount,int index,vector<int>& coins,vector<vector<int>>& dp){
        if(leftamount == 0)return 1;
        if(dp[index][leftamount] != -1)return dp[index][leftamount];

        int answer = 0;
        for(int i = index;i >= 0;i--){
            if(coins[i] <= leftamount){
                answer += f(leftamount - coins[i],i,coins,dp);
            }
        }
        return dp[index][leftamount] = answer;
    }
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1,-1));
        return f(amount,coins.size() - 1,coins,dp);
        
    }
};