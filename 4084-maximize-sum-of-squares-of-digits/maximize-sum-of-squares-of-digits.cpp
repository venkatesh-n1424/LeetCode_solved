class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
        // while(sum){
        //     int t=min(sum,9);
        //     res+=to_string(t);
        //     sum-=t;
        // }
        //optimal
        res.append(sum/9,'9');
        sum%=9;
        if(sum) res+=to_string(sum);
        int d=res.size();
        if(d>num) return "";
        if(d<num) res.append(num-d,'0');
        return res;
    }
};