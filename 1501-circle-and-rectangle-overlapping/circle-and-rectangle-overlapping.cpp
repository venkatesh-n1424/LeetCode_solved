class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x,y;
        if(x1>xCenter) x=x1;
        else if(x2<xCenter) x=x2;
        else x=xCenter;
        if(y1>yCenter) y=y1;
        else if(y2<yCenter) y=y2;
        else y=yCenter;
        int d=sqrt(pow(xCenter-x,2)+pow(yCenter-y,2));
        if(d<=radius) return true;
        return false;
        
    }
};