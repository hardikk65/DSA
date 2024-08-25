class Solution {
public:
    int numberofways(int index,string s,vector<int>& dp){
        if(index == s.size())return 1;
        if(dp[index] != -1)return dp[index];
        int single_digit = 0;
        int double_digit = 0;

        int num1 = s[index] - 48;
        if(num1 >= 1 && num1 <= 26){
            single_digit = numberofways(index + 1,s,dp);
        }
        if(index <= s.size() - 2){
            string num2;
            num2 += s[index];
            num2 += s[index + 1];
            int number = stoi(num2);
            if(number >= 10 && number <= 26){
                double_digit = numberofways(index + 2,s,dp);
            } 
        }
        return dp[index] = single_digit + double_digit;
    }
    int numDecodings(string s) {
        // if(s[0] == '0' || (s[s.size() - 2] >= '2' && s[s.size() - 1] == '0'))return 0;
        // int count = 0;
        // int cons_zero = 0;
        // for(int i = 0;i < s.size();i++){
        //     if(s[i] == '0')count++;
        //     else cons_zero = 0;
        //     cons_zero = max(cons_zero,count);
        // }
        // if(cons_zero > 1)return 0;


        // else{
            vector<int> dp(s.size(),-1);
            return numberofways(0,s,dp);

        // }

        
    }
};