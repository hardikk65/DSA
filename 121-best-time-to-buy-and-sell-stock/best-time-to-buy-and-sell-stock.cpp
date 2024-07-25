class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ptr = 0;
        int mover = 1;
        int answer = 0;
        while(mover != prices.size()){
            if(prices[mover] - prices[ptr] > 0){
                answer = max(answer,prices[mover] - prices[ptr]);
            }
            else if(prices[mover] - prices[ptr] <= 0)ptr = mover;

            mover++;
        }
        return answer;
        
    }
};