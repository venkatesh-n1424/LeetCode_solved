class Solution {
public:
    int dp[101][101];
    bool solve(string& s,int idx,int cnt){
        if(cnt<0) return false;
        if(idx==s.size()) return cnt==0;
        if(dp[idx][cnt]!=-1) return dp[idx][cnt];
        if(s[idx]=='(') return dp[idx][cnt]=solve(s,idx+1,cnt+1);
        if(s[idx]==')') return dp[idx][cnt]=solve(s,idx+1,cnt-1);
        return dp[idx][cnt]=solve(s,idx+1,cnt+1) || solve(s,idx+1,cnt-1) || solve(s,idx+1,cnt);
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};