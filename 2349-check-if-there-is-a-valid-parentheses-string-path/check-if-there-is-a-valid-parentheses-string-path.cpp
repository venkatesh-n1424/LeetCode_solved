class Solution {
public:
    int m,n;
    int t[101][101][201];
    bool dp(int i,int j,int b,vector<vector<char>>& grid){
        if(b<0) return false;
        if(i==m-1 && j==n-1) return t[i][j][b]=(b==0);
        if(t[i][j][b]!=-1) return t[i][j][b];
        if(i+1<m && dp(i+1,j,grid[i+1][j]=='('?b+1:b-1,grid)) 
            return t[i][j][b]=true;
        if(j+1<n && dp(i,j+1,grid[i][j+1]=='('?b+1:b-1,grid)) 
            return t[i][j][b]=true;
        return t[i][j][b]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        // function<int(int,int,int)> dp = [&](int i,int j,int b){
        //     if(b<0) return false;
        //     if(i==m-1 && j==n-1) return t[i][j][b]=(b==0);
        //     if(t[i][j][b]!=-1) return t[i][j][b];
        //     if(i+1<m && dp(i+1,j,grid[i+1][j]=='('?b+1:b-1) ) return t[i][j][b]=true;
        //     if(j+1<n && dp(i,j+1,grid[i][j+1]=='('?b+1:b-1) ) return t[i][j][b]=true;
        //     return t[i][j][b]=false;
        // };
        memset(t,-1,sizeof(t));
        return dp(0,0,grid[0][0]=='('?1:-1,grid);
    }
};