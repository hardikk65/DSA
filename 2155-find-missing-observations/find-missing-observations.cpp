class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum1 = mean*(rolls.size() + n) - accumulate(rolls.begin(),rolls.end(),0);
        if(sum1 < n || sum1 >6*n)return {};
        vector<int> answer(n,6);

        if(6*n == sum1)return answer;
        int acc_sum = 6*n;
        int i = 0;
        while(acc_sum != sum1){
            if(acc_sum - sum1 < 5){
                answer[i] -=   (acc_sum - sum1);
                acc_sum -= acc_sum - sum1;
                
            }
            else{
                answer[i] -= 5;
                acc_sum -= 5;
            }
            i++;
        }
        return answer;

        
    }
};