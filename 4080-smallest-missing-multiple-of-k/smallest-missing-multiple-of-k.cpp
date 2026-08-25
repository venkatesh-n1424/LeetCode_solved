class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        //brute
        // int i=1;
        // while(true){
        //     int m=k*i;
        //     bool yes=true;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[j]==m){
        //             yes=false;
        //             break;
        //         }
        //     }
        //     if(yes) return m;
        //     i++;
        // }
        // return 0;
        //hashmap
        unordered_set<int> mpp;
        for(int& num:nums) mpp.insert(num);
        int i=1;
        while(true){
            if(mpp.find(k*i)==mpp.end()) return k*i;
            i++;
        }
        return 0;
    }
};