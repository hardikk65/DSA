class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int mini = 1e9 + 1;

        int answer = -1;

        for(int i = 0;i < nums.size();i++){
            mini = min(mini,nums[i]);
            answer = max(answer,nums[i] - mini);
        }

        if(answer <= 0)return -1;
        return answer;

        
        return answer;

        
    }
};