class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(),0);
        dp[nums.size() - 1] = 1;
        for(int i = nums.size() - 2;i >= 0;i--){
            int a = nums[i];
            while(a != 0){
                if(i + a >= nums.size() - 1){
                    dp[i] = 1;
                    break;
                }
                dp[i] = dp[i]|dp[i + a];
                a--;
            }
        }
        return dp[0];
        
    }
};