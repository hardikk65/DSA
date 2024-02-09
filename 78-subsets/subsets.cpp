class Solution {
public:
    void powerset(vector<vector<int>>& answer,vector<int> nums){
        int number = nums[nums.size() - 1];
        if(nums.size() == 1){
            answer.push_back(nums);
            return;
        }
        nums.pop_back();
        powerset(answer,nums);
        int size = answer.size();
        vector<int> temp;
        for(int i = 0;i < size;i++){
            temp = answer[i];
            temp.push_back(number);
            answer.push_back(temp);
        }
        answer.push_back({number});
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        powerset(answer,nums);
        answer.push_back({});
        return answer;


    }
};