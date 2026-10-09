class Solution {
public:
    int minInsertions(string s) {
        int d=0,res=0;
        for(char& c:s){
            d+=(c==')'?-1:2);
            if(d<0){
                res++;
                d+=2;
            }
            else if(d&1 && c=='('){
                res++;
                d--;
            }
        }
        res+=d;
        return res;
    }
};