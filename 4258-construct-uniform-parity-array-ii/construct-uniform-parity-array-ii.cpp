class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oc=0,n=nums1.size();
        for(int& i : nums1){
            if(i%2) oc++;
        }
        if(oc==0 || oc==nums1.size()) return true;
        //brute
        // sort(nums1.begin(),nums1.end(),greater<int>());
        // for(int i=0;i<n;i++){
        //     if(nums1[i]%2==0){
        //         if(i==n-1) return false;
        //         for(int j=i+1;j<n;j++){
        //             if(nums1[j]%2)
        //             if(nums1[i]-nums1[j]<1) return false;
        //         }
        //     }
        // }
        // return true;
        //optimal
        int minele=*min_element(nums1.begin(),nums1.end());
        if(minele%2) return true;
        return false;
    }
};