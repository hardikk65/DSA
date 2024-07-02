class Solution {
public:

    int f(int leftamount,int index,vector<int>& coins,vector<vector<int>>& dp){
        if(leftamount == 0)return 1;
        if(dp[index][leftamount] != -1)return dp[index][leftamount];

        int answer = INT_MAX;
        for(int i = index;i >= 0;i--){
            if(coins[i] <= leftamount){
                answer = min(answer,f(leftamount - coins[i],i,coins,dp));
            }
        }
        if(answer == INT_MAX)return dp[index][leftamount] = INT_MAX;

        return dp[index][leftamount] = answer + 1;
    }
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1,-1));
        int answer = f(amount,coins.size() - 1,coins,dp);

        if(answer != INT_MAX)return answer - 1;

        return -1;
        
    }
};