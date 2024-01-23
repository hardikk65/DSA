class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<pair<int,char>> tempo;

        for(int i = 0;i < s.size();i++)freq[s[i]]++;

        for(auto x:freq)tempo.push_back({x.second,x.first});

        sort(tempo.rbegin(),tempo.rend());
        string word = "";

        for(int i = 0; i < tempo.size();i++){
            for(int j = 0;j < tempo[i].first;j++){
                word += tempo[i].second;
            }
        }

        return word;
        
    }
};