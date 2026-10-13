class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int> t){
        if(i==nums.size()){
            ans.push_back(t);
            return ans;
        }
        solve(nums,i+1,ans,t);
        t.push_back(nums[i]);
        solve(nums,i+1,ans,t);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        return solve(nums,0,ans,vector<int>{});
    }
};