class Solution {
public:
    bool judgeSquareSum(int c) {
        int start = 0;
        long long end = pow(c,0.5);

        if(c >= INT_MAX){
            return false;
        }

        // long long sum = 0;


        while(start <= end){
            // sum = ;
            if(start*start + end*end == c){
                return true;
            }
            else if(start*start + end*end > c){
                end = end - 1;
            }
            else{
                start = start + 1;
            }
        }
        return false;
    }
};