class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back(make_pair(value,timestamp));
    }
    
    string get(string key, int timestamp) {
        string res="";
        //if(mpp.find(key)==mpp.end()) return res;
        vector<pair<string,int>>& vals=mpp[key];
        int l=0,r=vals.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(vals[mid].second<=timestamp){
                res=vals[mid].first;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */