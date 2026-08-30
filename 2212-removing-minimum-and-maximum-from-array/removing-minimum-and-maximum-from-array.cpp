class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minele=INT_MAX,maxele=INT_MIN,maxidx,minidx;
        int mind;
        for(int i=0;i<n;i++){
            if(nums[i]>maxele){
                maxele=nums[i];
                maxidx=i;
            }
            if(nums[i]<minele){
                minele=nums[i];
                minidx=i;
            }
        }
        int l,r;
        if(maxidx<minidx){
            l=maxidx;
            r=minidx;
        }
        else{
            l=minidx;
            r=maxidx;
        }
        mind = min(l+1+n-r,min(n-l,r+1));
        return mind;
    }
};