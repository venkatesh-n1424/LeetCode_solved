class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        unordered_map<char,char> mpp={{')','('},{'}','{'},{']','['}};
        for(char& c:s){
            if(c=='('||c=='{'||c=='[') par.push(c);
            else if(!par.empty() && mpp[c]==par.top()) par.pop();
            else return false;
            
        }
        if(par.empty()) return true;
        return false;
    }
};