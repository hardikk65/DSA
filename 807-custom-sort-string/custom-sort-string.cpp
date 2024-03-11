class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> freq;
        for(auto c: s){
            freq[c]++;
        }

        string p = "";

        for(int i = 0;i < order.size();i++){
            if(freq[order[i]] != 0){
                while(freq[order[i]] != 0){
                    p += order[i];
                    freq[order[i]]--;
                }
            }
        }

        for(auto h: freq){
            if(h.second != 0){
                while(h.second != 0){
                    p += h.first;
                    h.second--;
                }
            }
        }
        return p;
        
    }
};