class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int> f(26,0);
        for(char& c:s) f[c-'a']++;
        string oddc="";
        for(int i=0;i<26;i++){
            if(f[i]%2==1){
                if(oddc.empty()) oddc+=(i+'a');
                else return "";
            }
            f[i]/=2;
        }
        string p="";
        for(int i=0;i<n/2;i++){
            bool valid=false;
            for(int ci=0;ci<26;ci++){
                char c=ci+'a';
                if(f[ci]==0 || c<target[i]) continue;
                if(c>target[i]){
                    f[ci]--;
                    p+=c;
                    for(int cci=0;cci<26;cci++){
                        if(f[cci]==0) continue;
                        p.append(f[cci],cci+'a');
                    }
                    string rev=p;
                    reverse(rev.begin(),rev.end());
                    return p+oddc+rev;
                }
                f[ci]--;
                p+=c;
                string copy=p;
                for(int cci=25;cci>=0;cci--){
                    if(f[cci]==0) continue;
                    copy.append(f[cci],cci+'a');
                }
                string rev=copy;
                reverse(rev.begin(),rev.end());
                if(copy+oddc+rev>target){
                valid=true;
                break;
                }
                f[ci]++;
                p.pop_back();
            }
            if(!valid) return "";
        }
        string rev=p;
        reverse(rev.begin(),rev.end());
        string res=p+oddc+rev;
        if(res>target) return res;
        return "";
    }
};