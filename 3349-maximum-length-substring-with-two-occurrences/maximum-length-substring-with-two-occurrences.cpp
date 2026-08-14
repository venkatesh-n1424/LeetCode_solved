class Solution {
public:
    int maximumLengthSubstring(string s) {
        //brute
        int n=s.size(),ml=INT_MIN;
        // for(i=0;i<n;i++){
        //     unordered_map<char,int> mpp;
        //     for(j=i;j<n;j++){
        //         mpp[s[j]]++;
        //         if(mpp[s[j]]>2) break;
        //     }
        //     ml=max(ml,j-i);
        //     if(j==n) break;
        // }
        //optimal-> sliding window
        unordered_map<char,int> mpp;
        int l=0,r=0;
        while(r<n){
            mpp[s[r]]++;
            if(mpp[s[r]]>2){
                ml=max(ml,r-l);
                while(mpp[s[r]]>2){
                    mpp[s[l]]--;
                    l++;
                }
            }
            r++;
        }
        ml=max(ml,r-l);
        return ml;
    }
};