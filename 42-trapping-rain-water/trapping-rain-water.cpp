class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixmax(n),sufixmax(n);
        prefixmax[0]=height[0];
        for(int i=1;i<n;i++) prefixmax[i]=max(prefixmax[i-1],height[i]);
        sufixmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--) sufixmax[i]=max(sufixmax[i+1],height[i]);
        int water=0;
        for(int i=0;i<n;i++){
            int leftmax=prefixmax[i],rightmax=sufixmax[i];
            water+=(min(leftmax,rightmax)-height[i]);
        }
        return water;
    }
};