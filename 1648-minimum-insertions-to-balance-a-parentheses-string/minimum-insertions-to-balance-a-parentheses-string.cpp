class Solution {
public:
    int minInsertions(string s) {
        int d=0,res=0;
        // for(char& c:s){
        //     d+=(c==')'?-1:2);
        //     if(d<0){
        //         res++;
        //         d+=2;
        //     }
        //     else if(d&1 && c=='('){
        //         res++;
        //         d--;
        //     }
        // }
        for(char& c:s){
            if(c=='('){
                d+=2;
                if(d&1) {
                    res++;
                    d--;
                }
            }
            else{
                d--;
                if(d<0){
                    res++;
                    d=1;
                }
            }
        }
        return res+d;
    }
};