class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum = 0;
        if(k == nums.size()){
            for(auto s: nums)sum += s;
            return sum;
        }
        int l = nums.size() - k;
        int r = nums.size() - 1;

        for(int i = l;i <= r;i++)sum += nums[i];
        int ans = sum;
        while(l != nums.size()){
            sum = sum - nums[l%nums.size()] + nums[(r + 1)%nums.size()];
            ans = max(ans,sum);
            l++;
            r++;
        }
        return ans;
    }
};