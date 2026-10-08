class Solution {
public:
    string removeOuterParentheses(string s) {
        int d=0;
        string res="";
        for(char& c:s){
            d+=(c==')'?-1:1);
            if((d==1 && c=='(')||(d==0 && c==')')) continue;
            res+=c;
        }
        return res;
    }
};