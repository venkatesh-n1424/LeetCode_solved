class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //brute
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<=i+n-1;j++){
        //         int idx=j%n;
        //         if(nums[idx]>nums[i]){
        //             ans[i]=nums[idx];
        //             break;
        //         }
        //     }
        // }
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()) st.pop();
            if(st.empty()){
                st.push(nums[i%n]);
            }
            else if(i<n){
                ans[i]=st.top();
                st.push(nums[i]);
            }
            else st.push(nums[i%n]);
        }
        return ans;
    }
};