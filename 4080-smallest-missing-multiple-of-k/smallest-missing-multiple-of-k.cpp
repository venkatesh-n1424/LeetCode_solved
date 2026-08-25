class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i=1;
        while(true){
            int m=k*i;
            bool yes=true;
            for(int j=0;j<nums.size();j++){
                if(nums[j]==m){
                    yes=false;
                    break;
                }
            }
            if(yes) return m;
            i++;
        }
        return 0;
    }
};