class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        set<string> res;
        function<void(string,int,int)> dp=[&](string cur,int i,int d){
            if(d<0) return;
            if(i==n){
                if(d==0) res.insert(cur);
                return;
            }
            if(s[i]!='(' && s[i]!=')') dp(cur+s[i],i+1,d);
            else{
                dp(cur+s[i],i+1,d+(s[i]==')'?-1:1));
                dp(cur,i+1,d);
            }
        };
        dp("",0,0);
        int max_size=0;
        for(const string& t:res) max_size=max(max_size,(int)t.size());
        vector<string> ans;
        for(const string& t:res){
            if(t.size()==max_size) ans.push_back(t);
        }
        return ans;
    }
};