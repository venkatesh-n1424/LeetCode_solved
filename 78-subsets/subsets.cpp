class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int ss=1<<n;
        vector<vector<int>> res;
        for(int num=0;num<ss;num++){
            vector<int> ls;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    ls.push_back(nums[i]);
                }
            }
            res.push_back(ls);
        }
        return res;
    }
};