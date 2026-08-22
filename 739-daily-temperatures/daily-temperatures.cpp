class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brute
         int n=temperatures.size();
        vector<int> res(n,0);
        // int j;
        // for(int i=0;i<n;i++){
        //     int c=0;
        //     for( j=i+1;j<n;j++){
        //         if(temperatures[i]<temperatures[j]){
        //             c++;
        //             break;
        //         }
        //         else{
        //             c++;
        //         }
        //     }
        //     if(j!=n)
        //     res[i]=c;
        // }
        // optimal
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=st.top().first){
                st.pop();
            }
            if(st.empty()){
            st.push(make_pair(temperatures[i],i));
            }
            else{
                res[i]=st.top().second-i;
                st.push(make_pair(temperatures[i],i));
            }
        }
        return res;
    }
};