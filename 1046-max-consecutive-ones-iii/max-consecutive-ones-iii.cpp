class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int max_len = 0;
        while(r != nums.size()){
            if(nums[r] == 1){
                max_len = max(max_len,r - l + 1);
                r = r + 1;
            }
            else{
                if(k > 0){
                    max_len = max(max_len,r - l + 1);
                    r = r + 1;
                    k = k - 1;
                }
                else{
                    if(nums[l] == 0)k = k + 1;
                    l = l + 1;
                }
            }
        }
        return max_len;
        
    }
};