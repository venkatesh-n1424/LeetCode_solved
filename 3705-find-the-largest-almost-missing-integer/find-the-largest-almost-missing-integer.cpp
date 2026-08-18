class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        //brute-O(n^3)
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        int res=-1;
        // for(int& num:nums){
        //     int c=0;
        //     int i=0,j=k-1;
        //     while(j<n){
        //         int subc=0;
        //         for(int x=i;x<=j;x++){
        //             if(nums[x]==num) subc++;
        //         }
        //         if(subc) c++;
        //         i++;
        //         j++;
        //     }
        //     if(c==1) res=max(res,num);
        // }
        //optimal-O(n)
        unordered_map<int,int> mpp;
        for(int& num:nums) mpp[num]++;

        if(k==1){
            for(int& num:nums){
                if(mpp[num]==1) res=max(res,num);
            }
        }
        else{
            if(mpp[nums[0]]==1) res=max(res,nums[0]);
            if(mpp[nums[n-1]]==1) res=max(res,nums[n-1]);
        }
        return res;
    }
};