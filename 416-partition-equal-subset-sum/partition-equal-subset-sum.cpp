class Solution {
public:
    bool f(int index, int sa,vector<int>& nums,vector<vector<int>>& dp){
        if(sa == 0)return true;
        if(index == 0)return (nums[0] == sa);
        if(dp[index][sa] != -1)return dp[index][sa];

        bool nt = f(index - 1, sa,nums,dp);
        bool t = false;

        if(sa >= nums[index]){
            t = f(index - 1,sa - nums[index],nums,dp);
        }
        return dp[index][sa] = t | nt;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++)sum += nums[i];
        if(sum % 2 != 0)return false;
        vector<vector<int>> dp(nums.size(),vector<int> ((sum/2) + 1,-1));
        return f(nums.size() - 1,sum/2,nums,dp);
        
    }
};