class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<bool>> ispal(n,vector<bool>(n,false));
        for(int l=1;l<=n;l++){
            for(int left=0;left<=n-l;left++){
                int right = left+l-1;
                 ispal[left][right] = ((s[left]==s[right]) && (l<=2 || ispal[left+1][right-1]));
            }
        }
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            if(i>0) dp[i]=dp[i-1];
            for(int j=0;j<=i-k+1;j++){
                if(ispal[j][i]){
                    int prev = j-1>=0 ? dp[j-1] : 0;
                    dp[i] = max(dp[i],prev+1);
                }
            }
        }
        return dp[n-1];
    }
};