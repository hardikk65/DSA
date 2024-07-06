class Solution {
public:
    int passThePillow(int n, int time) {
        int len = 2 * (n - 1);

        int efftime = time%len;

        if(efftime < n)return 1 + efftime;

        return 2*n - 1 - efftime;
        
    }
};