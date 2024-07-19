class Solution {
public: 
    int f(int i,int j,string& s,string& s1,vector<vector<int>>& dp){
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s1[j])return dp[i][j] = 1 + f(i - 1,j - 1,s,s1,dp);

        return dp[i][j] = max(f(i - 1,j,s,s1,dp),f(i,j - 1,s,s1,dp));
    }
    int longestPalindromeSubseq(string s) {
        if(s.size() == 1)return 1;
        string s1;
        for(int i = s.size() - 1;i >= 0;i--){
            s1 += s[i];
        }
        vector<vector<int>> dp(s.size(),vector<int>(s1.size(), - 1));
        int answer = f(s.size() - 1,s1.size() - 1,s,s1,dp);
        if(answer == 0)return 1;
        return answer;
    }
};