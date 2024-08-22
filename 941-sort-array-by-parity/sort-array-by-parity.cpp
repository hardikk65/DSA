class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> answer;
        for(auto i: nums){
            if(i%2 == 0)answer.push_back(i);
        }
        for(auto i: nums){
            if(i%2 == 1)answer.push_back(i);
        }
        return answer;
    }
};