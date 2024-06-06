class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mov = 0;
        int type1 = fruits[mov];
        int type2 = -1;
        int type1ind = 0;
        int type2ind = 0;
        for(auto c: fruits){
            if(c != type1){
                type2 = c;
                break;
            }
        }
        int type1cnt = 0;
        int type2cnt = 0;
        
        
        int ans = INT_MIN;
        while(mov != fruits.size()){
            if(fruits[mov] == type1){
                type1cnt++;
                type1ind = mov;}
            else if(fruits[mov] == type2){
                type2cnt++;
                type2ind = mov;}
            
            else{
                if(type2ind > type1ind){
                    type2cnt = type2ind - type1ind;
                    type1ind = mov;
                    type1 = fruits[mov];
                    type1cnt = 1;
                }
                else{
                    type1cnt = type1ind - type2ind;
                    type2ind = mov;
                    type2 = fruits[mov];
                    type2cnt = 1;
                }
            }
            ans = max(ans,type2cnt + type1cnt);
            mov++;
        }
        return ans;
        
    }
};