class Solution {
public:
    bool partition(int index, int sum, int target, int k,vector<int>& nums,vector<int>& temp){
        if(k == 0)return 1;
        if(sum == 0){
            return partition(0,target,target,k - 1,nums,temp);
        }

        for(int j = index;j < nums.size();j++){
            if(sum - nums[j] < 0 || temp[j] == 1)continue;

            temp[j] = 1;
            if(partition(j + 1,sum - nums[j],target,k,nums,temp))return true;
            temp[j] = 0;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        vector<int> temp(nums.size(),0);
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k != 0)return false;
        sum = sum/k;


        return partition(0,sum,sum,k,nums,temp);
        
    }
};