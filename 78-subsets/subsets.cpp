class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> solve(vector<int>& nums,int i,vector<int> t){
        if(i==nums.size()){
            ans.push_back(t);
            return ans;
        }
        solve(nums,i+1,t);
        t.push_back(nums[i]);
        solve(nums,i+1,t);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums,0,vector<int>{});
    }
};