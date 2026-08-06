class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //brute
        int n1=nums1.size(),n2=nums2.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    bool have=false;
                    for(int k=j+1;k<n2;k++){
                        if(nums2[j]<nums2[k]){
                            have=true;
                            ans.emplace_back(nums2[k]);
                            break;
                        }
                    }
                    if(!have) ans.emplace_back(-1);
                }
            }
        }
        return ans;
    }
};