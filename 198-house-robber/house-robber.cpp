class Solution {
public:

    int maxrob(int index,vector<int> &nums,vector<int> &dp){

        if(index >= nums.size())return 0;
        if(dp[index] != -1)return dp[index];

        int maxi = INT_MIN;
        for(int k = 2;k < nums.size();k++){
            maxi = max(maxi,nums[index] + maxrob(index + k,nums,dp));
        }
        dp[index] = maxi;

        return dp[index];

    }
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2)return max(nums[0],nums[1]);
        
        vector<int> dp(nums.size(),-1);
        // dp[nums.size() - 3] = nums[nums.size() - 3] + nums[nums.size() - 1];
        
        return max(maxrob(0,nums,dp),maxrob(1,nums,dp));
    }
};