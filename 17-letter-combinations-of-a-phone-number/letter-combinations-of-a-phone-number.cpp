class Solution {
public:
    void combinations(vector<string>& answer,string s, int i,char p,int size,map<char,string> alphabets,string digits){
        if(p != ' ')s+=p;
        if(s.size() == size){
            answer.push_back(s);
            return;
        }
        for(int k = 0;k < alphabets[digits[i]].size();k++){
            cout<<digits[i]<<endl;
            combinations(answer,s,i + 1,alphabets[digits[i]][k],size,alphabets,digits);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> alphabets;
        vector<string> answer;
        if(digits.size() == 0){
            return answer;
        }
        alphabets['2'] = "abc";
        alphabets['3'] = "def";
        alphabets['4'] = "ghi";
        alphabets['5'] = "jkl";
        alphabets['6'] = "mno";
        alphabets['7'] = "pqrs";
        alphabets['8'] = "tuv";
        alphabets['9'] = "wxyz";

        combinations(answer,"",0,' ',digits.size(),alphabets,digits);

        return answer;
        
        
    }
};