class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        for(int len=k;len<=n;len++){
            string res="";
            for(int start=0;start<=n-len;start++){
                string temp = s.substr(start,len);
                int ones=0;
                for(char& c:temp){
                    if(c=='1') ones++;
                }
                if(ones==k){
                    if(res.empty() || temp<res) res=temp; 
                }
            }
            if(!res.empty()) return res;
        }
        return "";
    }
};