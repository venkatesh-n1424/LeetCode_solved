class Solution {
public:
    // int n;
    // int t[100001];

    // int solve(int i, vector<int>& prefixSum) {
    //     if(i == n-1) {
    //         return prefixSum[n-1];
    //     }

    //     if(t[i] != -1)
    //         return t[i];

    //     int take = prefixSum[i] - solve(i+1, prefixSum);

    //     int skip = solve(i+1, prefixSum);

    //     return t[i] = max(take, skip);
    // }
    int stoneGameVIII(vector<int>& stones) {
        //recursion and memoization  - Topm down
        // n = stones.size();
        // memset(t, -1, sizeof(t));

        // vector<int> prefixSum(n, 0);
        // prefixSum[0] = stones[0];
        

        // for(int i = 1; i < n; i++) {
        //     prefixSum[i] = prefixSum[i-1] + stones[i];
        // }

        // return solve(1, prefixSum); //Alice turns first
        //bottom-up
        int n=stones.size();
        vector<int> prefix(n,0);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        vector<int> dp(n);
        dp[n-1]=prefix[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i] = max(dp[i+1],prefix[i]-dp[i+1]);
        }
        return dp[1];
    }
};