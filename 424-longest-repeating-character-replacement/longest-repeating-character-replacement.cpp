class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> freq;
        for(auto a: s)freq[a]++;

        int ans = 0;
        for(auto key:freq){
            int r = 0;
            int l = 0;
            int temp = k;
            while(r != s.size()){
                if(s[r] == key.first){
                    ans = max(ans,r - l + 1);
                    r++;
                }
                else if(s[r] != key.first && temp > 0){
                    ans = max(ans,r - l + 1);
                    temp--;
                    r++;
                }
                else{
                    if(s[l] != key.first){
                        temp++;
                    }
                    l++;
                }
            }

        }
        return ans;
        
    }
};