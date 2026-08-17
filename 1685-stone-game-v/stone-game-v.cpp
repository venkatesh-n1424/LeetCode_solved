class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l,int r,vector<int>& prefixsum){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int score=0;
        for(int mid=l;mid<=r-1;mid++){
            int leftsum=prefixsum[mid]-(l>0?prefixsum[l-1]:0);
            int rightsum=prefixsum[r]-prefixsum[mid];
            if(leftsum<rightsum){
                score=max(score,leftsum+solve(l,mid,prefixsum));
            }
            else if(leftsum>rightsum){
                score=max(score,rightsum+solve(mid+1,r,prefixsum));
            }
            else{
                score=max(score,max(leftsum+solve(l,mid,prefixsum),rightsum+solve(mid+1,r,prefixsum)));
            }
        }
        return dp[l][r]=score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int l=0,r=n-1;
        vector<int> prefixsum(n,0);
        prefixsum[0]=stoneValue[0];
        for(int i=1;i<n;i++) prefixsum[i]=prefixsum[i-1]+stoneValue[i];
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,prefixsum);
    }
};