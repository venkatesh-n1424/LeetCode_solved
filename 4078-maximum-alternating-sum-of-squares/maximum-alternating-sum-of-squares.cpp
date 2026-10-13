class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) nums[i]=abs(nums[i]);
        sort(nums.begin(),nums.end());
        int minidx=0,maxidx=n-1;
        while(minidx<maxidx){
            sum+=(nums[maxidx]*nums[maxidx]-nums[minidx]*nums[minidx]);
            maxidx--;
            minidx++;
        }
        if(minidx==maxidx) sum+=nums[minidx]*nums[minidx];
        return sum;
    }
};