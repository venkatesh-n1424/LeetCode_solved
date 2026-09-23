class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0,n=nums.size();
        for(int& i:nums) sum+=i;
        int t=sum-x,lsa=-1;
        if(t<0) return lsa;
        int l=0,r=0,cur=0;
        while(r<n){
            cur+=nums[r];
            while(cur>t){
                cur-=nums[l++];
            }
            if(cur==t) lsa=max(lsa,r-l+1);
            r++;
        }
        if(lsa==-1) return lsa;
        return n-lsa;
    }
};