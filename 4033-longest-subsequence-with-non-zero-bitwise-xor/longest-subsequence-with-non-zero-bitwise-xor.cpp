class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0,aze=0,n=nums.size();
        for(int i:nums){
            x^=i;
            if(i==0) aze++;
        }
        if(x==0 && aze!=n) return n-1;
        else if(aze==n) return 0;
        return n; 
    }
};