class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int size = nums.size();
        int total_sum = 0;
        for(auto i:nums)total_sum += i;
        int sum1 = total_sum;
        int sum2 = total_sum;
        int maxi = max(total_sum,size - total_sum);
        vector<int> answer;

        int zero_cnt = 0;
        for(auto i:nums){
            if(i == 0)zero_cnt++;
            if(i == 1)total_sum--;
            maxi = max(maxi,zero_cnt + total_sum);
        }

        zero_cnt = 0;
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i] == 0)zero_cnt++;
            if(nums[i] == 1)sum1--;
            if(zero_cnt + sum1 == maxi)answer.push_back(i + 1);
        }

        if(sum2 == maxi)answer.push_back(0);
        if(size - sum2 == maxi)answer.push_back(nums.size());

        return answer;
        
    }
};