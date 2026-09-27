class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(char& c:s){
            if(c==')'){
                string cur="";
                while(st.top()!='('){
                    cur+=st.top();
                    st.pop();
                }
                st.pop();
                for(char& i:cur) st.push(i);
            }
            else{
                st.push(c);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};