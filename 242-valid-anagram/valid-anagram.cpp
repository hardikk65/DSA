class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mymap;
        map<char,int> mymap1;
        for(int i = 0; i < s.size();i++){
            mymap[s[i]]++;
        }for(int i = 0;i < t.size();i++){
            mymap1[t[i]]++;
        }
        map<char,int>::iterator it = mymap.begin();
        if(mymap1.size() != mymap.size()){
            return false;
        }
        while(it != mymap.end()){
            if(mymap1[it->first] != mymap[it->first]){
                return false;
            }++it;
        }
        return true;
        
    }
};