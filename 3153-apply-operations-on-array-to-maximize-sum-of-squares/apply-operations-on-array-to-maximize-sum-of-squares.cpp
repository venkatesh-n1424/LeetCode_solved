class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32,0);
        int mod=1e9+7,res=0;
        // for(int bitidx=0;bitidx<32;bitidx++){
        //     int cnt=0;
        //     for(int& i:nums){
        //         if(i&(1<<bitidx)) cnt++;
        //     }
        //     bits[bitidx]=cnt;
        // }
        for(int& n:nums){
            for(int i=0;i<32;i++){
                bits[i]+=(n>>i)&1;
            }
        }
        while(k--){
            int t=0;
            for(int bitidx=0;bitidx<32;bitidx++){
                if(bits[bitidx]>0){
                    t|=(1<<bitidx);
                    bits[bitidx]--;
                }
            }
            res = (res+(long)t*t)%mod;
        }
        return res%mod;
    }
};