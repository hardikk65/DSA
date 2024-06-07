class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        map<int,int> prefsum;
        prefsum[0] = 1;

        int count = 0;
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            int remove = sum - goal;
            count += prefsum[remove];
            prefsum[sum]++;
        }
        return count;
    }
};