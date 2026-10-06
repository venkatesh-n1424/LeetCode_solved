class Solution {
public:
    int minAddToMakeValid(string s) {
        int d=0,res=0;
        for(char& c:s){
            d+=(c=='('?1:-1);
            if(d<0){
                res++;
                d=0;
            }
        }
        if(d!=0) res+=d;
        return res;
    }
};