class Solution {
public:
    int characterReplacement(string s, int k) {
        //brute-Tc-O(n^2),Sc-O(26)
        int n=s.size(),res=1;
        // for(int i=0;i<n;i++){
        //     vector<int> f(26,0);
        //     int maxf=0;
        //     for(int j=i;j<n;j++){
        //         maxf=max(maxf,++f[s[j]-'A']);
        //         int changes=(j-i+1)-maxf;
        //         if(changes<=k){
        //             res=max(res,j-i+1);
        //         }
        //         else break;
        //     }
        // }
        //better - Tc-O(2N*26) , Sc-O(26)
        // int i=0,j=0,maxf=0;
        // vector<int> f(26,0);
        // while(j<n){
        //     maxf=max(maxf,++f[s[j]-'A']);
        //     while((j-i+1)-maxf>k){
        //         f[s[i]-'A']--;
        //         i++;
        //         maxf=0;
        //         for(int k=0;k<26;k++) maxf=max(maxf,f[k]);
        //     }
        //     res=max(res,j-i+1);
        //     j++;
        // }
        //optimal-O(n),Sc-O(26)
        int i=0,j=0,maxf=0;
        vector<int> f(26,0);
        while(j<n){
            maxf=max(maxf,++f[s[j]-'A']);
            if((j-i+1)-maxf>k){
                f[s[i]-'A']--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};