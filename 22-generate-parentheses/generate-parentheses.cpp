class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        function<void(int,string,int)> bt = [&](int start,string cur,int d){
            if(d<0) return;
            if(start==n*2){
                if(d==0) res.emplace_back(cur);
                return;
            }
            bt(start+1,cur+'(',d+1);
            bt(start+1,cur+')',d-1);
        };
        bt(0,"",0);
        return res;
    }
};