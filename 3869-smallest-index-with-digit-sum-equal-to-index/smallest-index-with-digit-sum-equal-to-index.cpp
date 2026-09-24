class Solution {
public:
    int ds(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==ds(nums[i])) return i;
        }
        return -1;
    }
};