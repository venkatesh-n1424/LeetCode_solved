class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int> r;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || i==k || j==k || digits[i]==0 || digits[k]&1) continue;
                    r.insert(digits[i]*100 + digits[j]*10 + digits[k]);
                }
            }
        }
        return r.size();
    }
};