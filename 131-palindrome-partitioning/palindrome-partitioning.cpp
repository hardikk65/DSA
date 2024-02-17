class Solution {
public:
    void combination(vector<vector<string>>& answer,vector<string> temp,string s){
        if(s.size() == 0){
            return;
        }
        if(s.size()==1){
            temp.push_back(s);
            answer.push_back(temp);
            return ;
        }

        int n = s.size();
        for(int i= 1 ;i<=n;i++){
            string og = s.substr(0,i);
            reverse(og.begin(),og.end());
            if(i == s.size() && og == s.substr(0,i)){
                temp.push_back(og);
                answer.push_back(temp);
                break;
            }
            if(og == s.substr(0,i)){
                temp.push_back(og);
                combination(answer,temp,s.substr(i,n - i));
                temp.pop_back();
                
            }
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> temp;
        combination(answer,temp,s);

        return answer;
        
    }
};