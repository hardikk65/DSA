class Solution {
public:
    bool canJump(vector<int>& nums) {
        // vector<bool> dp(nums.size(),0);
    
        if(nums.size() == 1)return true;
        int mov = nums.size() -2;
        int nearest_ptr = nums.size() - 1;
        while(mov >= 0){
            if(nums[mov] >= nearest_ptr - mov){
                // dp[mov] = 1;
                nearest_ptr = mov;
            }
            mov--;
        }
        return (mov + 1 == nearest_ptr);
        
    }
};