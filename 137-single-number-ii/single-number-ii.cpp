class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //brute Tc-O(n*logm) Sc-O(logm) , m=n/3 +1;
        unordered_map<int,int> mpp;
        for(int& i:nums) mpp[i]++;
        for(auto it:mpp){
            if(it.second==1) return it.first;
        }
        return 0;
    }
};