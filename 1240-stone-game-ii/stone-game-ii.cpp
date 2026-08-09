class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int p,int i,int M,int n,vector<int>& piles){
        if(i>=n) return 0;
        if(dp[p][i][M]!=-1) return dp[p][i][M];
        int stones=0;
        int res=(p ? -1 : INT_MAX);
        for(int x=1;x<=min(2*M,n-i);x++){
            stones+=piles[i+x-1];
            if(p){
                res=max(res,stones+solve(0,i+x,max(M,x),n,piles));
            }
            else{
                res=min(res,solve(1,i+x,max(M,x),n,piles));
            }
        }
        return dp[p][i][M]=res;
    }
    int stoneGameII(vector<int>& piles) {
        dp=vector<vector<vector<int>>>(2,vector<vector<int>>(101,vector<int>(101,-1)));
        return solve(1,0,1,piles.size(),piles);
    }
};