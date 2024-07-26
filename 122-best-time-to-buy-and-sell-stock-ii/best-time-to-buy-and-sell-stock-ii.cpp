class Solution {
public:
    int f(int index,vector<int>& nums,vector<int>&dp){
        
        if(index == nums.size())return 0;

        if(dp[index] != -1)return dp[index];
        int maxi = 0;
        for(int i = index + 1;i < nums.size();i++){
            if(nums[i] > nums[index]){
                maxi= max(maxi,nums[i] - nums[index] + f(i + 1,nums,dp));
            }
        }
        return dp[index] = max(maxi,f(index + 1,nums,dp));
        
    }
    int maxProfit(vector<int>& prices) {

        vector<int> dp(prices.size(),-1);
        return f(0,prices,dp);
        
    }
};