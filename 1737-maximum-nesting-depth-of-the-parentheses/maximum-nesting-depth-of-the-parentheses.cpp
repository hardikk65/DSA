class Solution {
public:
    int maxDepth(string s) {

        int maxi = 0;
        int open = 0;

        for(int j = 0;j < s.size();j++){
            if(s[j] == '('){
                open++;
            }
            if(s[j] == ')'){
                maxi = max(open,maxi);
                open--;
            }
        }
        return maxi;
        
    }
};