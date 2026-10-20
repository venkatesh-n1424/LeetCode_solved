class Solution {
public:
    vector<vector<int>> ans;
    void per(vector<int>& nums,int i,vector<int> p){
        if(i==nums.size()){
            ans.push_back(p);
            return;
        }
        int n=p.size();
        for(int k=0;k<=n;k++){
            vector<int> f(p.begin(),p.begin()+k);
            vector<int> l(p.begin()+k,p.begin()+n);
            f.push_back(nums[i]);
            f.insert(f.end(),l.begin(),l.end());
            per(nums,i+1,f);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums,0,vector<int>{});
        return ans;
    }
};