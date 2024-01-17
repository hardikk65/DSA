class Solution {
public:

    int distance(int x1,int y1,int x2,int y2){

        int dist = pow(pow((x2 - x1),2) + pow((y2 - y1),2),0.5);
        return dist;
    }

    
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int x3 = x1;
        int y3 = y2;

        int x4 = x2;
        int y4 = y1;


        if(((x1 <= xCenter) && (x2 >= xCenter)) && ((y1 <= yCenter) && (y2 >= yCenter))){
            return true;
        }
        else if((x1 <= xCenter) && (x2 >= xCenter)){
            if(y2 <= yCenter){
                return (distance(xCenter,yCenter,xCenter,y2) - radius <= 0);
            }
            else{
                return (distance(xCenter,yCenter,xCenter,y1) - radius <= 0);
            }
        }
        else if((y1 <= yCenter) && (y2 >= yCenter)){
            if(x2 <= xCenter){
                return (distance(xCenter,yCenter,x2,yCenter) - radius <= 0);
            }
            else{
                return (distance(xCenter,yCenter,x1,yCenter) - radius <= 0);
            }
        }

        return min(min(distance(xCenter,yCenter,x1,y1),distance(xCenter,yCenter,x2,y2)),min(distance(xCenter,yCenter,x3,y3),distance(xCenter,yCenter,x4,y4))) - radius <= 0;

        
        
    }
};