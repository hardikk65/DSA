class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            map<char,int> freq;
            int start = i;
            while(start != s.size()){
                if(freq[s[start]] != 0)break;
                freq[s[start]]++;
                ans = max(ans,start - i + 1);
                start++;
            }
        }
        return ans;
        
    }
};