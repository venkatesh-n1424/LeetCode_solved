class Solution {
public:
    vector<int> nsel(vector<int>& nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=nums[i]) st.pop();
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top().second;
            st.push(make_pair(nums[i],i));
        }
        return ans;
    }
    vector<int> psel(vector<int>& nums){
        vector<int> ans;
        stack<pair<int,int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=nums[i]) st.pop();
            if(st.empty()) ans.emplace_back(-1);
            else ans.emplace_back(st.top().second);
            st.push(make_pair(nums[i],i));
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l=psel(heights),r=nsel(heights);
        int res=INT_MIN,n=heights.size();
        for(int i=0;i<n;i++){
            res=max(res,heights[i]*(r[i]-l[i]-1));
        }
        return res;
    }
};