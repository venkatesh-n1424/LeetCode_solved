class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});
        int start,end;
        for(int i=0;i<n;i++){
            start=0;
            if(i>0 && nums[i]==nums[i-1]) start=end+1;
            int s=ans.size();
            end=s-1;
            for(int j=start;j<s;j++){
                vector<int> list=ans[j];
                list.emplace_back(nums[i]);
                ans.push_back(list);
                }
            }
        return ans;
    }
};