class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int quot = numBottles;
        long long answer = 0;
        while(quot != 0){
            if(quot < numExchange){
                answer += quot;
                quot = (quot/numExchange);
            }
            else{
                answer += quot - quot%numExchange;
                quot = (quot/numExchange) + (quot%numExchange);
            }
            
        }

        return answer;
        
    }
};