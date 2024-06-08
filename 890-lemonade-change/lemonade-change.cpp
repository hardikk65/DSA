class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] != 5)return false;
        map<int,int> billi;

        for(int i = 0;i < bills.size();i++){
            if(bills[i] == 5)billi[bills[i]]++;
            else if(bills[i] == 10){
                if(billi[5] <= 0)return false;
                else{
                    billi[5]--;
                    billi[10]++;
                }
            }
            else if(bills[i] == 20){
                
                if(billi[10] >= 1 && billi[5] >= 1){
                    billi[10]--;
                    billi[5]--;
                    billi[20]++;
                }
                else if(billi[5] >= 3){
                    billi[5] = billi[5] - 3;
                    billi[20]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};