class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char,int> m1;
        for(int i = 0;i < s.size();i++){
            m1[s[i]] = i;
        }
        int sum = 0;

        for(int i = 0;i < t.size();i++){
            sum += abs(m1[t[i]] - i);
        }
        return sum;
    }
};