class Solution {
public:
    int scoreOfParentheses(string s) {
        int d=0,res=0;
        char prev=' ';
        for(char& c:s){
            d+=(c=='('?1:-1);
            if(prev=='(' && c==')') res+=(1<<d);
            prev=c;
        }
        return res;
    }
};