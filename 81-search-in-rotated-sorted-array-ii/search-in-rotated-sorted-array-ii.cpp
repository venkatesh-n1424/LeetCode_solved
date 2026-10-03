class Solution {
public:
    bool bs(vector<int>& nums,int t,int s,int e){
        if(s>e) return false;
        int mid=s+(e-s)/2;
        if(nums[mid]==t) return true;
        if(nums[s]==nums[mid] && nums[mid]==nums[e]) return bs(nums,t,s+1,e-1);
        if(nums[s]<=nums[mid]){
            if(t>=nums[s] && t<nums[mid]){
                return bs(nums,t,s,mid-1);
            }
            return bs(nums,t,mid+1,e);
        }
        if(t>nums[mid] && t<=nums[e]) return bs(nums,t,mid+1,e);
        return bs(nums,t,s,mid-1);
    }
    bool search(vector<int>& nums, int target) {
        // int l=0,h=nums.size()-1;
        // while(l<=h){
        //     int mid=l+(h-l)/2;
        //     if(nums[mid]==target) return true;
        //     if(nums[l]==nums[mid] && nums[mid]==nums[h]){
        //         l++;
        //         h--;
        //         continue;
        //     }
        //     if(nums[l]<=nums[mid]){
        //         if(nums[l]<=target && nums[mid]>=target) h=mid-1;
        //         else l=mid+1;
        //     }
        //     else{
        //         if(nums[mid]<=target && nums[h]>=target) l=mid+1;
        //         else h=mid-1;
        //     }
        // }
        // return false;
        //recursion
        return bs(nums,target,0,nums.size()-1);
    }
};