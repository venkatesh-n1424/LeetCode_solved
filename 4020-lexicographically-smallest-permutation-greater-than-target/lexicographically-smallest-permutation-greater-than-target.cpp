class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        map<int,int> fm;
        for(char& c:s) fm[c]++;
        string res="";
        for(int i=0;i<n;i++){
            char t=target[i];
            if(fm[t]>0){
                fm[t]--;
                string largest="";
                for(int j=25;j>=0;j--){
                    char c = j+'a';
                    if(fm[c]>0){
                        largest.append(fm[c],c);
                    }
                }
                if(largest>target.substr(i+1)){
                    res+=t;
                    continue;
                }
                fm[t]++;
            }
            for(int j=t-'a'+1;j<26;j++){
                char c = j+'a';
                if(fm[c]>0){
                    res+=c;
                    fm[c]--;
                    string smallest="";
                    for(int k=0;k<26;k++){
                        char temp=k+'a';
                        if(fm[temp]>0){
                            smallest.append(fm[temp],temp);
                        }
                    }
                    return res+smallest;
                }
            }
            return "";
        }
        return "";
    }
};