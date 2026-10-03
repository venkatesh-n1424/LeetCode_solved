class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        // function<int(string,int,int)> 
        auto check=[&](string s,int ov,int cv){
            int d=0,res=0,l=0;
            for(int r=0;r<n;r++){
                d+=(s[r]==')'?cv:ov);
                if(d<0){
                    l=r+1;
                    d=0;
                }
                if(d==0){
                    res=max(res,r-l+1);
                }
            }
            return res;
        };
        string rev=s;
        reverse(rev.begin(),rev.end());
        return max(check(s,1,-1),check(rev,-1,1));
    }
};