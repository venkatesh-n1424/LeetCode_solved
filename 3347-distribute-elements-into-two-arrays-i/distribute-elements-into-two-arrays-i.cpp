class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        //brute
        int n=nums.size();
        vector<int> arr1,arr2,res(n);
        arr1.emplace_back(nums[0]);
        arr2.emplace_back(nums[1]);
        int i1=0,i2=0;
        for(int i=2;i<n;i++){
            if(arr1[i1]>arr2[i2]){
                arr1.emplace_back(nums[i]);
                i1++;
            }
            else{
                arr2.emplace_back(nums[i]);
                i2++;
            }
        }
        arr1.reserve(n);
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;

    }
};