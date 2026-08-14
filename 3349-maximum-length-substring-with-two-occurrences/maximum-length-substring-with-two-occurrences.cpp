class Solution {
public:
    int maximumLengthSubstring(string s) {
        //brute
        int n=s.size(),i,j,ml=INT_MIN;
        for(i=0;i<n;i++){
            unordered_map<char,int> mpp;
            for(j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp[s[j]]>2) break;
            }
            ml=max(ml,j-i);
            if(j==n) break;
        }
        return ml;
    }
};