class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int k=k1+k2;
        //TLE
        // priority_queue<int> pq;
        // for(int i=0;i<n;i++) pq.push(abs(nums1[i]-nums2[i]));
        // while(k>0 && pq.top()>0){
        //     int t=pq.top();
        //     pq.pop();
        //     pq.push(t-1);
        //     k--;
        // }
        // long long sum=0;
        // while(!pq.empty()){
        //     long long t=pq.top();
        //     sum+=(t*t);
        //     pq.pop();
        // }
        vector<long long> freq(1e5+1,0);
        long long totaldiff=0,maxdiff=0;
        for(int i=0;i<n;i++){
            long long diff=abs(nums1[i]-nums2[i]);
            freq[diff]++;
            totaldiff+=diff;
            maxdiff=max(maxdiff,diff);
        }
        if(totaldiff<=k) return 0;
        for(int d=maxdiff;d>0;d--){
            if(k==0) break;
            long long moves=min((long long)k,freq[d]);
            freq[d]-=moves;
            freq[d-1]+=moves;
            k-=moves;
        }
        long long sum=0;
        for(long long d=1;d<=maxdiff;d++){
            sum+=(d*d*freq[d]);
        }
        return sum;
    }
};