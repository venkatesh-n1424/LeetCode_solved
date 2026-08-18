class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        //brute
        int n=nums.size();
        int res=-1;
        for(int& num:nums){
            int c=0;
            int i=0,j=k-1;
            while(j<n){
                int subc=0;
                for(int x=i;x<=j;x++){
                    if(nums[x]==num) subc++;
                }
                if(subc) c++;
                i++;
                j++;
            }
            if(c==1) res=max(res,num);
        }
        return res;
    }
};