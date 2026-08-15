class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0,n=nums.size();
        bool aez=true;
        for(const int& i : nums){
            x^=i;
            if(i!=0) aez=false;
        } 
        if(aez) return 0;
        return x ? n : n-1;
    }
};