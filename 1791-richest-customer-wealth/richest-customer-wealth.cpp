class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int answer = INT_MIN;

        for(auto i: accounts){
            int sum = 0;
            for(auto j: i){
                sum += j;
            }
            answer = max(answer,sum);
        }
        return answer;
        
    }
};