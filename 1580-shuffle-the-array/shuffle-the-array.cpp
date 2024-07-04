class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x1 = 0;
        int y1 = n;

        vector<int> answer;

        for(int i = 0;i < n;i++){
            answer.push_back(nums[x1]);
            answer.push_back(nums[y1]);
            x1++;
            y1++;
        }
        return answer;
        
    }
};