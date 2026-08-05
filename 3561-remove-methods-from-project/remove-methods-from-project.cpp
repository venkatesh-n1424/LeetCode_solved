class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        vector<bool> suspicious(n,false);
        for(auto &edge:invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].emplace_back(v);
            inDegree[v]++;
        }
        //bfs
        queue<int> que;
        que.push(k);
        suspicious[k]=true;
        while(!que.empty()){
            int curr=que.front();
            que.pop();

            for(int &nbr: adj[curr]){
                inDegree[nbr]--;
                if(!suspicious[nbr]){
                    que.push(nbr);
                    suspicious[nbr]=true;
                }
            }
        }
        vector<int> res;
        bool cantRemove = false;
        for(int i=0;i<n;i++){
            if(suspicious[i] && inDegree[i]>0){
                //we can't remove anything. return 0 to n-1;
                cantRemove=true;
                break;
            }
            if(!suspicious[i]) res.emplace_back(i);
        }
        if(cantRemove){
            vector<int> vec(n);
            for(int i=0;i<n;i++) vec[i]=i;
            return vec;
        }
        return res;
    }
};