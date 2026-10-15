class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size(),res=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                unordered_set<int> s;
                for(int k=i;k<=j;k++)
                    if(!s.contains(nums[k])) s.insert(nums[k]);
                res+=pow(s.size(),2);
            }
          
        }
        return res;
    }
};