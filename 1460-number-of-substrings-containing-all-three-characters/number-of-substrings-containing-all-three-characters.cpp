class Solution {
public:
    int numberOfSubstrings(string s) {

        int a = -1;
        int b = -1;
        int c =  -1;

        int count = 0;

        int r = 0;

        while(r != s.size()){
            if(s[r] == 'a')a = r;
            else if(s[r] == 'b')b = r;
            else if(s[r] == 'c')c = r;
            if((a != -1) && (b != -1) && (c != -1)){
                count = count + 1 + min(a,min(b,c));
            }
            r++;
        }
        return count;
        
    }
};