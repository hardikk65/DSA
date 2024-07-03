class Solution {
public:
    int targetsum(int index,int currsum,vector<int>& nums,int target,int totalsum,vector<vector<int>>& dp){
        if(index == nums.size()){
            if(2*currsum - totalsum == target)return 1;
            return 0;
        }
        if(dp[index][currsum] != -1)return dp[index][currsum];
        return dp[index][currsum] = targetsum(index + 1,currsum + nums[index],nums,target,totalsum,dp) + targetsum(index + 1,currsum,nums,target,totalsum,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        for(auto c : nums)totalsum += c;
        vector<vector<int>> dp(nums.size(),vector<int>(totalsum + 1,-1));
        return targetsum(0,0,nums,target,totalsum,dp);
        
    }
};