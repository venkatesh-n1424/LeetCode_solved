class Solution {
public:
    string key(string str){
        sort(str.begin(),str.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mpp;
        for(auto s:strs){
            string k=key(s);
            mpp[k].emplace_back(s);
        }
        vector<vector<string>> res;
        for(const auto& it:mpp){
            res.emplace_back(it.second);
        }
        return res;
    }
};