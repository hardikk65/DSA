class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        vector<int> dp(nums.size(), 100000);

        int lstindex = nums.size() - 1;
        int mov = nums.size() - 2;
        while(mov >= 0){
            if(nums[mov] >= lstindex - mov){
                dp[mov] = 1;
            }
            else{
                int temp = nums[mov];
                while(temp != 0){
                    dp[mov] = min(dp[mov],1 + dp[mov + temp]);
                    temp--;
                }
            }
            mov--;
        }
        return dp[0];
        
    }
};