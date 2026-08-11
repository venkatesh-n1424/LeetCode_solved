class Solution {
public:
    bool ls(int x,vector<int>& nums){
        int n=nums.size();
        for(int i:nums) if(i==x) return true;
        return false;
    }
    int missingInteger(vector<int>& nums) {
        int n=nums.size(),sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) sum+=nums[i];
            else break;
        }
        int x=sum;
        while(ls(x,nums)){
            x++;
        }
        return x;
    }
};