class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> answer;
        int count = 0;
        for(auto i:words){
            for(auto j:i){
                if(j == x){
                    answer.push_back(count);
                    break;
                }
            }
            count++;
        }
        return answer;
        
    }
};