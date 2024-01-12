class Solution {
public:
    string largestOddNumber(string num) {
        int start = 0;
        long long end = num.size() - 1;
        // cout<<stoi("4")<<endl;

        while(start <= end){
            int a = num[end] - 48;
            if(a%2 != 0){
                
                return num.substr(0,end+1);
            }
            else{
                end--;
            }
        }
        return "";
    }
};