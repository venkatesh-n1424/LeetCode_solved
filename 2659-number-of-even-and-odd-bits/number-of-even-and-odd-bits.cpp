class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2,0);
        for(int i=31;i>=0;i--){
            if(n>>i & 1 ==1){
                if(i&1) res[1]++;
                else res[0]++;
            }
        }
        return res;
    }
};