class Solution {
public:
    int f(int index,int buy,int count,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(count == 2 || index == prices.size())return 0;
        if(dp[index][buy][count] != -1)return dp[index][buy][count];
        int profit = 0;

        if(!buy){
            profit = max(-prices[index] + f(index + 1,1,count,prices,dp),f(index + 1,0,count,prices,dp));
        }
        if(buy){
            profit = max(prices[index] + f(index + 1,0,count + 1,prices,dp),f(index + 1,1,count,prices,dp));
        }

        return dp[index][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,0,0,prices,dp);
        
    }
};