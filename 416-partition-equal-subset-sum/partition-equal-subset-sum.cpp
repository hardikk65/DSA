class Solution {
public:
    bool f(int index, int sa, int sb, vector<int>& nums,vector<vector<int>>& dp){
        if(index == nums.size())return (sa == sb);
        if(dp[index][sa] != -1)return dp[index][sa];
        return dp[index][sa] = f(index + 1,sa + nums[index],sb,nums,dp) | f(index + 1,sa,sb + nums[index],nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++)sum += nums[i];
        vector<vector<int>> dp(nums.size(),vector<int> (sum + 1,-1));
        return f(0,0,0,nums,dp);
        
    }
};