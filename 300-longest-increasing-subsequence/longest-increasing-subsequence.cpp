class Solution {
public:

    int f(int index,int prev_ind,vector<int>& nums,vector<vector<int>>& dp){
        if(index == nums.size())return 0;
        if(dp[index][prev_ind + 1] != -1) return dp[index][prev_ind + 1];
        int takes = 0;
        if(prev_ind == -1){
            takes = 1 + f(index + 1,index,nums,dp);
        }
        if(prev_ind != -1 && nums[index] > nums[prev_ind]){
            takes = 1 + f(index + 1,index,nums,dp);
        }
        return dp[index][prev_ind + 1] = max(takes,f(index + 1,prev_ind,nums,dp));
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size() + 1,-1));
        return f(0,-1,nums,dp);
        
    }
};