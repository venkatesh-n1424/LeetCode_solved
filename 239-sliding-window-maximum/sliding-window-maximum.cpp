class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //brute - Tc-O((n-k)*k), Sc-O(n-k)
        // int n=nums.size();
        // int i=0,j=k-1;
        // vector<int> res;
        // while(j<n){
        //     int max_ele = *max_element(nums.begin()+i,nums.begin()+j+1);
        //     res.emplace_back(max_ele);
        //     i++;
        //     j++;
        // }
        // return res;
        deque<int> dq;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                res.emplace_back(nums[dq.front()]);
            }
        }
        return res;
    }
};