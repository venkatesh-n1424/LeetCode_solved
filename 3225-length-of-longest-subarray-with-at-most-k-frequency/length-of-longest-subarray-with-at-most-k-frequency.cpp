class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxs=1;
        int i=0,j=0;
        //brute
        // while(i<n){
        //     unordered_map<int,int> mpp;
        //     int j=i;
        //     while(j<n){
        //         if(++mpp[nums[j]]<=k) j++;
        //         else{
        //             maxs=max(maxs,j-i);
        //             break;
        //         }
        //     }
        //     if(j==n){
        //         maxs=max(maxs,j-i);
        //         break;
        //     }
        //     i++;
        // }
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            maxs=max(maxs,j-i+1);
            j++;
        }
        return maxs;
    }
};