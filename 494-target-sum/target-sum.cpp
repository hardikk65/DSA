class Solution {
public:
    int targetsum(int index,int currsum,vector<int>& nums,int target,int totalsum){
        if(index == nums.size()){
            if(2*currsum - totalsum == target)return 1;
            return 0;
        }
        return targetsum(index + 1,currsum + nums[index],nums,target,totalsum) + targetsum(index + 1,currsum,nums,target,totalsum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        for(auto c : nums)totalsum += c;
        return targetsum(0,0,nums,target,totalsum);
        
    }
};