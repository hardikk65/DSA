class Solution {
public:
    long long getLucky(string s, int k) {
        string convert;

        for(int i = 0;i < s.size();i++){
            convert += to_string(s[i] - 97 + 1);
        }
        while(k--){
            int number = 0;
            for(int i = 0;i < convert.size();i++){
                // int a = stoi(convert[i]);
                number += convert[i] - 48;
            }
            convert = to_string(number);
        }
        // cout<<convert<<endl;
        return stoll(convert);
        
    }
};