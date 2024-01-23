class Solution {
public:
    string frequencySort(string s) {

        string st;

        unordered_map<char,int>mp;

        for(auto x:s) mp[x]++;

        vector<pair<int, char>>vec;
        for(auto x:mp) 
        {
        vec.push_back({x.second, x.first});
        }

        sort(vec.rbegin(), vec.rend());

        for(auto x:vec) {
        int a= x.first;
        while(a--) {
        st += x.second;
        }
        }

        return st;
        
        
    }
};