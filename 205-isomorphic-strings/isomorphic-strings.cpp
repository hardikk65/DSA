class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // map<char,int> s1;
        // map<char,int> t1;
        set<char> a;
        set<char> b;
        map<int,int> nva_map;

        for(int i = 0;i < s.size();i++){
            a.insert(s[i]);
            b.insert(t[i]);
        }

        if(a.size() != b.size()){
            return false;
        }
        for(int i = 0;i < s.size();i++){
            if(nva_map.find(s[i]) == nva_map.end() || (nva_map[s[i]] == t[i])){
               nva_map[s[i]] = t[i];
            }
            else{
                return false;
            }
        }

        return true;


        
    }
};