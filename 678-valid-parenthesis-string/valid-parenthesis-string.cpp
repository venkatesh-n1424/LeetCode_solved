class Solution {
public:
    // int dp[101][101];
    // bool solve(string& s,int idx,int cnt){
    //     if(cnt<0) return false;
    //     if(idx==s.size()) return cnt==0;
    //     if(dp[idx][cnt]!=-1) return dp[idx][cnt];
    //     if(s[idx]=='(') return dp[idx][cnt]=solve(s,idx+1,cnt+1);
    //     if(s[idx]==')') return dp[idx][cnt]=solve(s,idx+1,cnt-1);
    //     return dp[idx][cnt]=solve(s,idx+1,cnt+1) || solve(s,idx+1,cnt-1) || solve(s,idx+1,cnt);
    // }
    bool checkValidString(string s) {
        //dp(memoization) - Tc-O(n^2) Sc-O(n^2)
        // without memoization-Tc-O(3^n) sc-O(n)
        // memset(dp,-1,sizeof(dp));
        // return solve(s,0,0);
        //optimal(range-based)-TC-O(n) Sc-O(n)
        int min=0,max=0;
        for(char& c:s){
            if(c=='('){
                min++;
                max++;
            }
            else if(c==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        return min==0;
    }
};