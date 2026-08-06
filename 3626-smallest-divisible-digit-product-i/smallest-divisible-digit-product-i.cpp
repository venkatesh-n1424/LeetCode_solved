class Solution {
public:
    int pro(int n){
        int res=1;
        while(n){
            res*=(n%10);
            n/=10;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        while(n){
            if(pro(n)%t==0) return n;
            n++;
        }
        return 0;
    }
};