class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            bool check = true;
            for(int j = i;j < i + nums.size() - 1;j++){
                if(nums[j%nums.size()] > nums[(j + 1)%nums.size()]){
                    check = false;
                    break;
                }
            }
            if(check == true){
                return true;
            }
        }
        return false;
        
    }
};