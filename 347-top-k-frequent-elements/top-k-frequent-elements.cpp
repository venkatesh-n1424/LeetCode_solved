class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //brute
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(auto i:nums) mpp[i]++;
        // vector<pair<int,int>> vec(mpp.begin(),mpp.end());
        // sort(vec.begin(),vec.end(),[](const auto& a,const auto& b){
        //     return a.second>b.second;
        // });
         vector<int> res;
        // while(k--){
        //     res.emplace_back(vec[k].first);
        // }
        //optimal
        vector<vector<int>> buc(n+1);
        for(const auto& f:mpp){
            buc[f.second].emplace_back(f.first);
        }
        for(int i=n;i>0;i--){
            for(auto num:buc[i]){
                if(k!=0) {
                    res.emplace_back(num);
                    k--;
                }
                else break;
            }
        }
        return res;
    }
};