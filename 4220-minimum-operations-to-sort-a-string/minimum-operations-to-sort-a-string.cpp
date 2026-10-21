class Solution {
public:
    bool sorted(string s){
        int n=s.size();
        bool sort=true;
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1]){
                sort=false;
                break;
            }
        }
        return sort;
    }
    int minOperations(string s) {
        int n=s.size();
        if(sorted(s)) return 0;
        if(n<3) return -1;
        string t1=s,t2=s;
        sort(t1.begin(),t1.begin()+n-1);
        sort(t2.begin()+1,t2.end());
        if(sorted(t1) || sorted(t2)) return 1;
        t1=s;
        t2=s;
        sort(t1.begin(),t1.begin()+n-1);
        sort(t1.begin()+1,t1.end());
        sort(t2.begin()+1,t2.end());
        sort(t2.begin(),t2.begin()+n-1);
        if(sorted(t1) || sorted(t2)) return 2;
        t1=s;
        t2=s;
        sort(t1.begin(),t1.begin()+n-1);
        sort(t1.begin()+1,t1.end());
        sort(t1.begin(),t1.begin()+n-1);
        sort(t2.begin()+1,t2.end());
        sort(t2.begin(),t2.begin()+n-1);
        sort(t2.begin()+1,t2.end());
        if(sorted(t1) || sorted(t2)) return 3;
        return -1;
    }
};