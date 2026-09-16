class Solution {
public:
    int mod=1e9+7;
    int dp[1001][1001];
    //vector<vector<int>> dp;
    //top-down
    // int solve(int n,int k,int i){
    //     if(k==0) return 1;
    //     if(i>=n) return 0;
    //     if(dp[k][i]!=-1) return dp[k][i]%mod;
    //     long long skip = solve(n,k,i+1)%mod;
    //     long long take=0;
    //     for(int j=i+1;j<n;j++){
    //         take=(take+solve(n,k-1,j))%mod;
    //     }
    //     return dp[k][i]=(skip+take)%mod;
    // }
    int numberOfSets(int n, int k) {
        //dp.resize(1001,vector<int>(1001,-1));
        //return solve(n,k,0);
        //bottom-up
        for(int i=0;i<n;i++) dp[0][i]=1;
        for(int K=1;K<=k;K++){
            vector<int> prevrowsum(n+1,0);
            for(int x=n-1;x>=0;x--){
                prevrowsum[x]=(prevrowsum[x+1]+dp[K-1][x])%mod;
            }
            for(int i=n-1;i>=0;i--){
                //int take=0;
                // for(int j=i+1;j<n;j++){
                //     take=(take+dp[K-1][j])%mod;
                // }
                int take=prevrowsum[i+1]%mod;
                int skip = dp[K][i+1]%mod;
                dp[K][i]=(take+skip)%mod;
            }
        }
       return dp[k][0];
    }
};