class Solution {
public:
    //Recursion TC-O(2^n) Sc-O(n)
    // vector<vector<int>> ans;
    // vector<vector<int>> solve(vector<int>& nums,int i,vector<int> t){
    //     if(i==nums.size()){
    //         ans.push_back(t);
    //         return ans;
    //     }
    //     solve(nums,i+1,t);
    //     t.push_back(nums[i]);
    //     solve(nums,i+1,t);
    //     return ans;
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        //return solve(nums,0,vector<int>{});
        //iterative
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});
        for(int& num:nums){
            int n=ans.size();
            for(int i=0;i<n;i++){
                vector<int> list=ans[i];
                list.push_back(num);
                ans.push_back(list);
            }
        }
        return ans;
    }
};