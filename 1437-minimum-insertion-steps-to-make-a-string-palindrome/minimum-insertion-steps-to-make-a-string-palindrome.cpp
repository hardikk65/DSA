class Solution {
public:
    int answer(int i,int j,string& s,vector<vector<int>>& dp){
        if(i >= j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == s[j])return dp[i][j] = answer(i + 1,j - 1,s,dp);

        return dp[i][j] = min(1 + answer(i + 1,j,s,dp),1 + answer(i,j - 1,s,dp));
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return answer(0,s.size() - 1,s,dp);
        
    }
};