class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int min_ele=nums[0],max_ele=nums[n-1];
        unordered_map<int,int> mpp;
        vector<int> res;
        for(auto i:nums) mpp[i]++;
        for(int i=min_ele+1;i<max_ele;i++){
            if(!mpp[i]) res.emplace_back(i);
        }
        return res;
    }
};