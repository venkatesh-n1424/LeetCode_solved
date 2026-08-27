class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int i=0,j=0,n=s.size(),res=0;
        while(j<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
            }
            else{
                res=max(res,j-i);
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            j++;
            }
        }
        return res=max(res,j-i);
    }
};