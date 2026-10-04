class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //brute Tc-O(n*logm) Sc-O(logm) , m=n/3 +1;
        // unordered_map<int,int> mpp;
        // for(int& i:nums) mpp[i]++;
        // for(auto it:mpp){
        //     if(it.second==1) return it.first;
        // }
        // return 0;
        //bitwise Tc-O(32n) Sc-O(1)
        int n=nums.size();
        // int ans=0;
        // for(int bitidx=0;bitidx<32;bitidx++){
        //     int cnt=0;
        //     for(int i=0;i<n;i++){
        //         if(nums[i]&(1<<bitidx)) cnt++;
        //     }
        //     if(cnt%3==1) ans = ans | (1<<bitidx);
        // }
        // return ans;
        //sorting Tc-O(nlogn) Sc-O(1)
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i+=3){
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[n-1];
    }
};