class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        //brute
        // int n=s.size();
        // for(int len=k;len<=n;len++){
        //     string res="";
        //     for(int start=0;start<=n-len;start++){
        //         string temp = s.substr(start,len);
        //         int ones=0;
        //         for(char& c:temp){
        //             if(c=='1') ones++;
        //         }
        //         if(ones==k){
        //             if(res.empty() || temp<res) res=temp; 
        //         }
        //     }
        //     if(!res.empty()) return res;
        // }
        // return "";
        //sliding window
        int n=s.size(),i=0,j=0,ones=0;
        string res="";
        while(j<n){
            if(s[j]=='1') ones++;
            while(ones>k || s[i]=='0'){
                if(s[i]=='1'){
                    ones--;
                }
                i++;
            }
            if(ones==k){
                int len=j-i+1;
                string temp=s.substr(i,len);
                if(res.empty() || len<res.size() || (temp.size()==res.size() && temp<res)) res=temp;
            }
            j++;
        }
        return res;
    }
};