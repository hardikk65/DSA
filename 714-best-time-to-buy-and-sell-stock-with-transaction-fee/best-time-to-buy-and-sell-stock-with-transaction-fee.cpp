class Solution {
public:
    int f(int index,int buy,int fee,vector<int>& prices,vector<vector<int>>& dp){
        if(index >= prices.size())return 0;
        if(dp[index][buy] != -1)return dp[index][buy];
        int profit = 0;
        if(!buy){
            profit = max(-prices[index] + f(index + 1,1,fee,prices,dp) - fee,f(index + 1,0,fee,prices,dp));
        }
        if(buy){
            profit = max(prices[index] + f(index + 1,0,fee,prices,dp),f(index + 1,1,fee,prices,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,0,fee,prices,dp);
        
    }
};