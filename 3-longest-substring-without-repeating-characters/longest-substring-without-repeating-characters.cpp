class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char,int> freq;
        for(int i = 0;i < s.size();i++){
            int start = i;
            while(start != s.size()){
                if(freq[s[start]] != 0)break;
                freq[s[start]]++;
                ans = max(ans,start - i + 1);
                start++;
            }
            freq.clear();
        }
        return ans;
        
    }
};