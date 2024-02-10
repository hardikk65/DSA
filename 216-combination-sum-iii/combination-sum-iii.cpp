class Solution {

public:
    void calcsum(vector<vector<int>>& answer, vector<int>& nums, int index, int target, int sum, vector<int>& candidates,int count,int k) {
        if (sum == target && count == k) {
            answer.push_back(nums);
            return;
        }
        if (sum > target || index == candidates.size() || count == k) {
            return;
        }

        nums.push_back(candidates[index]);
        count = count + 1;
        calcsum(answer, nums, index + 1, target, sum + candidates[index], candidates,count,k);
        nums.pop_back();
        count = count - 1;
        

        calcsum(answer, nums, index + 1, target, sum, candidates,count,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for(int i = 1;i <= 9;i++){
            candidates.push_back(i);
        }
        vector<vector<int>> answer;
        vector<int> nums;
        calcsum(answer, nums, 0, n, 0, candidates,0,k);
        return answer;
    }
};