class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0;i < nums.size();i++){
            if(nums[i]&1)nums[i] = 1;
            else{
                nums[i] = 0;
            }
        }
        map<int,int> prefsum;
        prefsum[0] = 1;
        int count = 0;
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            int remove = sum - k;
            count += prefsum[remove];
            prefsum[sum]++;
        }
        return count;
        
    }
};