class Solution {

public:
    void calcsum(vector<vector<int>>& answer, vector<int>& nums, int index, int target, int sum, vector<int>& candidates) {
        if (sum == target) {
            answer.push_back(nums);
            return;
        }
        if (sum > target || index == candidates.size()) {
            return;
        }

        nums.push_back(candidates[index]);
        calcsum(answer, nums, index, target, sum + candidates[index], candidates);
        nums.pop_back();

        calcsum(answer, nums, index + 1, target, sum, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> nums;
        calcsum(answer, nums, 0, target, 0, candidates);
        return answer;
    }
};