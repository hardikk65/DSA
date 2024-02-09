class Solution {
public:
    void parent(vector<string>& answer,string s,int open,int close,int digi){
    if((s.size() == digi) && open-close != 0){
        return;
    }
    if((s.size() == digi) && open - close == 0){
        answer.push_back(s);
        return;
    }
    if(open - close < 0){
        return;
    }
    parent(answer,s + '(',open + 1,close,digi);
    parent(answer,s + ')',open,close + 1,digi);
    return;
}
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        parent(answer,"(",1,0,n*2);
        return answer;
        
    }
};