class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    vector<vector<ll>> pt;
    int solve(vector<int>& nums){
        int n=nums.size();
        if(n<3) return 1;
        vector<int> left_arr,right_arr;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root) left_arr.emplace_back(nums[i]);
            else right_arr.emplace_back(nums[i]);
        }
        ll x=solve(left_arr)%mod;
        ll y=solve(right_arr)%mod;
        ll z=pt[n-1][left_arr.size()];
        return (int)(((x*y)%mod*z)%mod);
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pt.resize(n+1);
        for(int i=0;i<=n;i++){
            pt[i]=vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                pt[i][j]=(pt[i-1][j]+pt[i-1][j-1])%mod;
            }
        }
        return (solve(nums)-1)%mod;
    }
};