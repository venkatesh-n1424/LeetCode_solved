class Solution {
public:
    int maxArea(vector<int>& height) {
        //brute
        int n=height.size();
        int max_area=INT_MIN;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         max_area=max(max_area,min(heights[i],heights[j])*(j-i));
        //     }
        // }
        //Two-pointer
        int i=0,j=n-1;
        while(i<j){
            max_area=max(max_area,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return max_area;
    }
};