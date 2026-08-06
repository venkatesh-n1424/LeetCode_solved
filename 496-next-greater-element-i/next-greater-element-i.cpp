class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //brute
        int n1=nums1.size(),n2=nums2.size();
        vector<int> ans(n1,-1);
        unordered_map<int,int> d;
        // for(int i=0;i<n1;i++){
        //     for(int j=0;j<n2;j++){
        //         if(nums1[i]==nums2[j]){
        //             bool have=false;
        //             for(int k=j+1;k<n2;k++){
        //                 if(nums2[j]<nums2[k]){
        //                     have=true;
        //                     ans.emplace_back(nums2[k]);
        //                     break;
        //                 }
        //             }
        //             if(!have) ans.emplace_back(-1);
        //         }
        //     }
        // }
        //stacks
        stack<int> s;
        for(int i=n2-1;i>=0;i--){
            if(s.empty()){
                s.push(nums2[i]);
                d[nums2[i]]=-1;
            }
            else if(s.top()>nums2[i]){
                d[nums2[i]]=s.top();
                s.push(nums2[i]);
            }
            else{
                while(!s.empty() && s.top()<=nums2[i]){
                    s.pop();
                }
                if(s.empty()){
                     s.push(nums2[i]);
                     d[nums2[i]]=-1;
                }
                else{
                    d[nums2[i]]=s.top();
                    s.push(nums2[i]);
                }
            }
        }
        for(int i=0;i<n1;i++){
            ans[i]=d[nums1[i]];
        }
        return ans;
    }
};