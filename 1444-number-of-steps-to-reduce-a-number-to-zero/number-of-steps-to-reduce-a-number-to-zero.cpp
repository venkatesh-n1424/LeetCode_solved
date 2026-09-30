class Solution {
public:
    int solve(int n,int s){
        if(n==0) return s;
        if(n&1) return solve(n-1,s+1);
        return solve(n/2,s+1);
    }
    int numberOfSteps(int num) {
        return solve(num,0);
    }
};