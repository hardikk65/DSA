class Solution {
public:
    bool judgeSquareSum(int c) {
        int start = 0;
        long long end = pow(c,0.5);

        if(c >= INT_MAX){
            return false;
        }

        long long sum = 0;


        while(start <= end){
            sum = start*start + end*end;
            if(sum == c){
                return true;
            }
            else if(sum > c){
                end = end - 1;
            }
            else{
                start = start + 1;
            }
        }
        return false;
    }
};