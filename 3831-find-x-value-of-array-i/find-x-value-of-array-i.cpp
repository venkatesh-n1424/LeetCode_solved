class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        //brute
        int n=nums.size();
        vector<long long> res(k,0);
        // for(int i=0;i<n;i++){
        //     long long prod=1;
        //     for(int j=i;j<n;j++){
        //         prod*=nums[j];
        //         res[prod%k]++;
        //     }
        // }
        //DP
        vector<vector<long long>> dp(n,vector<long long>(k,0));
        //dp[i] [r] = number of subarrays ending at i with product % k == r
        dp[0][nums[0]%k]=1;
        for(int i=1;i<n;i++){
            dp[i][nums[i]%k]=1;
            for(long long r=0;r<k;r++){
                long long col = (r*nums[i])%k;
                dp[i][col]+=dp[i-1][r];
            }
        }
        for(int r=0;r<k;r++){
            for(int i=0;i<n;i++){
                res[r]+=dp[i][r];
            }
        }
        return res;
    }
};