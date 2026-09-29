class Solution {
public:
    int bs(vector<int>& arr,int s,int e,int t){
        if(s>e) return -1;
        int m=s+(e-s)/2;
        if(arr[m]==t) return m;
        if(arr[m]>t) return bs(arr,s,m-1,t);
        return bs(arr,m+1,e,t);
    }
    int search(vector<int>& nums, int target) {
        //iterative-Tc-O(logn),sc-O(1);
        int s=0,e=nums.size()-1;
        // while(s<=e){
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]==target) return mid;
        //     else if(nums[mid]<target) s=mid+1;
        //     else e=mid-1;
        // }
        // return -1;
        //recursive
        return bs(nums,s,e,target);
    }
};