class Solution {
public:
    int romanToInt(string s) {

        map<char,int> roman{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int answer = 0;

        for(int i = 0;i < s.size() - 1;i++){
            (roman[s[i + 1]] > roman[s[i]])?answer -= roman[s[i]]:answer += roman[s[i]];
        }
        answer += roman[s[s.size() - 1]];
        roman.clear();
        return answer;

        
    }
};