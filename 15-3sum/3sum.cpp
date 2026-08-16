class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //brute
        int n=nums.size();
        vector<vector<int>> ans;
        //set<vector<int>> st;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int> t={nums[i],nums[j],nums[k]};
        //                 sort(t.begin(),t.end());
        //                 st.insert(t);
        //             }
        //         }
        //     }
        // }
        //better
        // for(int i=0;i<n;i++){
        //     unordered_set<int> mpp;
        //     for(int j=i+1;j<n;j++){
        //         int k=-(nums[i]+nums[j]);
        //         if(mpp.find(k)!=mpp.end()){
        //             vector<int> t={nums[i],nums[j],k};
        //             sort(t.begin(),t.end());
        //             st.insert(t);
        //         }
        //         mpp.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());
        //optimal
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }else if(sum>0){
                    k--;
                }
                else{
                   
                    ans.emplace_back(vector<int>{nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};