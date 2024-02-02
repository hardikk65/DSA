class Solution {
public:
    bool isPerfectSquare(int num) {
   double s = (double)pow(num,0.5);
   if(s==(int)pow(num,0.5)){
       return true;
   }
   else {
   return false;}

    }
};