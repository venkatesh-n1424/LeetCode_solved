class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,pro=1,t=n;
        while(t){
            int r=t%10;
            sum+=r;
            pro*=r;
            t/=10;

        }
        if(n%(sum+pro)==0) return true;
        return false;
    }
};