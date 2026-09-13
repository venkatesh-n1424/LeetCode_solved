class Solution {
public:
    int countoverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2,int ro,int co){
        int c=0;
        int n=img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int orr=i+ro,oc=j+co;
                if((orr>=0 && orr<n) && (oc>=0 && oc<n)){
                    if(img1[i][j]==1 &&img2[orr][oc]==1) c++;
                }
            }
        }
        return c;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size(),c=0;
        for(int ro=-n+1;ro<n;ro++){
            for(int co=-n+1;co<n;co++){
                c=max(c,countoverlaps(img1,img2,ro,co));
            }
        }
        return c;
    }
};