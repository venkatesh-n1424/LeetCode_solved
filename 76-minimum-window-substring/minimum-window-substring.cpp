class Solution {
public:
    string minWindow(string s, string t) {
        //brute
        int m=s.size(),n=t.size(),si=-1,minlen=INT_MAX;
        // for(int i=0;i<m;i++){
        //     vector<int> fm(256,0);
        //     for(int j=0;j<n;j++) fm[t[j]]++;
        //     int cnt=0;
        //     for(int j=i;j<m;j++){
        //         if(fm[s[j]]>0) cnt++;
        //         fm[s[j]]--;
        //         if(cnt==n){
        //             if(j-i+1<minlen){
        //                 si=i;
        //                 minlen=j-i+1;
        //                 break;
        //             }
        //         }
        //     }
        // }
        //sliding window
        int cnt=0;
        vector<int> fm(256,0);
        for(int i=0;i<n;i++) fm[t[i]]++;
        int l=0,r=0;
        while(r<m){
            if(fm[s[r]]>0) cnt++;
            fm[s[r]]--;
            while(cnt==n){
                int len=r-l+1;
                if(len<minlen){
                    si=l;
                    minlen=len;
                }
                fm[s[l]]++;
                if(fm[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(si!=-1) return s.substr(si,minlen);
        return "";
    }
};