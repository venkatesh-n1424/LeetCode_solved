class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        // int minele=INT_MAX,maxele=INT_MIN,maxidx,minidx;
        // int mind;
        // for(int i=0;i<n;i++){
        //     if(nums[i]>maxele){
        //         maxele=nums[i];
        //         maxidx=i;
        //     }
        //     if(nums[i]<minele){
        //         minele=nums[i];
        //         minidx=i;
        //     }
        // }
        // int l,r;
        // if(maxidx<minidx){
        //     l=maxidx;
        //     r=minidx;
        // }
        // else{
        //     l=minidx;
        //     r=maxidx;
        // }
        // mind = min(l+1+n-r,min(n-l,r+1));
        // return mind;
        auto [min_it,max_it] = minmax_element(nums.begin(),nums.end());
        int min_idx = distance(nums.begin(),min_it);
        int max_idx = distance(nums.begin(),max_it);
        int l = min(min_idx,max_idx);
        int r = max(min_idx,max_idx);
        return min(l+1+n-r,min(n-l,r+1));
    }
};