class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxd=0;
        for(char& c:s){
            if(c=='('){
                st.push(c);
                maxd=max(maxd,(int)st.size());
            }
            else if(c==')') st.pop();
        }
        return maxd;
    }
};