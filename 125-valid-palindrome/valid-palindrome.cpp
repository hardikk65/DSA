class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> check;
        for(int i = 0;i < s.length();i++){
            if(s[i]>= 'A' && s[i]<= 'Z'){
                s[i] = s[i] - 'A' + 'a';
                check.push_back(s[i]);
            }
            else if((s[i] >= 'a' && s[i] <='z') ||(s[i] >= '0' && s[i] <='9')){
                check.push_back(s[i]);
            }
        }

        for(int j = check.size() - 1;j >= 0;j--){
            if(check[j] != check[check.size() - j - 1]){
                return false;
            }
        }
        return true;
        
    }
};