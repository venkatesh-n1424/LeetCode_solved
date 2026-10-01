class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute Tc-O(n1+n2),sc-O(n1+n2);
        // int n1=nums1.size(),n2=nums2.size();
        // int n=n1+n2;
        // vector<int> res;
        // int i=0,j=0;
        // while(i<n1 && j<n2){
        //     if(nums1[i]<=nums2[j]){
        //         res.emplace_back(nums1[i++]);
        //     }
        //     else res.emplace_back(nums2[j++]);
        // }
        // while(i<n1) res.emplace_back(nums1[i++]);
        // while(j<n2) res.emplace_back(nums2[j++]);
        // if(n&1) return (double)res[n/2];
        // return (double)(res[n/2]+res[n/2-1])/2;
        //better TC-O(n1+n2) SC-O(1)
        // int n1=nums1.size(),n2=nums2.size();
        // int n=n1+n2;
        // int idx1=n/2-1,idx2=n/2,ele1,ele2;
        // int i=0,j=0,c=0;
        // while(i<n1 && j<n2){
        //     if(nums1[i]<=nums2[j]){
        //         if(idx1==c) ele1=nums1[i];
        //         if(idx2==c) ele2=nums1[i];
        //         c++;
        //         i++;
        //     }
        //     else{
        //         if(idx1==c) ele1=nums2[j];
        //         if(idx2==c) ele2=nums2[j];
        //         c++;
        //         j++;
        //     }
        // }
        // while(i<n1){
        //     if(idx1==c) ele1=nums1[i];
        //     if(idx2==c) ele2=nums1[i];
        //     c++;
        //     i++;
        // }
        // while(j<n2){
        //     if(idx1==c) ele1=nums2[j];
        //     if(idx2==c) ele2=nums2[j];
        //     c++;
        //     j++;
        // }
        // if(n&1) return (double)ele2;
        // return (double)(ele1+ele2)/2;
        //optimal-Binary Search- TC-O(log(min(n1,n2))) Sc-O(1)
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int n=n1+n2;
        int left=(n+1)/2;
        int l=0,h=n1;
        double res;
        while(l<=h){
            int mid1=l+(h-l)/2;
            int mid2=left-mid1;;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n&1) res=max(l1,l2);
                else res=(double)(max(l1,l2)+min(r1,r2))/2;
                break;
            }
            else if(l1>r2) h=mid1-1;
            else l=mid1+1;
        }
        return res;
    }
};
