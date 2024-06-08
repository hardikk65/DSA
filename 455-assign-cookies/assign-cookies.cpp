class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0 || g.size() == 0)return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        
        int si = 0;
        int gi = 0;
        int answer = 0;
        while(gi != g.size()){
            if(s[si] >= g[gi]){
                gi++;
                answer++;
            } 
            si++;
            if(si == s.size())return answer;
        }
        return answer;
        
    }
};