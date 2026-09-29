class Solution {
public:
    int fib(int n) {
        //recursive - Tc-(golden_ratio^n),sc-O(n)
        // if(n<2) return n;
        // return fib(n-1)+fib(n-2);
        //iterative-Tc-O(n),sc-O(1)
        if(n<2) return n;
        int a=0,b=1,c;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};