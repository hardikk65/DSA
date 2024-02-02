class Solution {
public:
    bool isPerfectSquare(int num) {
   
   if((double)pow(num,0.5)==(int)pow(num,0.5)){
       return true;
   }
   else {
   return false;}

    }
};