class Solution {
public:

    int calc_setbit(int n){
        int set_bits = 0;
        while(n != 0){
            n = n&(n - 1);
            set_bits++;
        }
        return set_bits;
    }
    vector<int> countBits(int n) {

        vector<int> answer;

        for(int i = 0;i < n + 1;i++){
            answer.push_back(calc_setbit(i));
        }
        return answer;
        
    }
};