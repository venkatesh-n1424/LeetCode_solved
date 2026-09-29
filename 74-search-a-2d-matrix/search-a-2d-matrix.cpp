class Solution {
public:
    int m,n;
    // bool bs(vector<int>& mat,int s,int e,int t){
    //     if(s>e) return false;
    //     int m=s+(e-s)/2;
    //     if(mat[m]==t) return true;
    //     if(mat[m]>t) return bs(mat,s,m-1,t);
    //     return bs(mat,m+1,e,t);
    // }
    bool bs(int s,int e,vector<vector<int>>& mat, int t){
        if(s>e) return false;
        int mid=s+(e-s)/2;
        int row=mid/n;
        int col=mid%n;
        if(mat[row][col]==t) return true;
        if(t<mat[row][col]) return bs(s,mid-1,mat,t);
        return bs(mid+1,e,mat,t);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute - Tc-O(mn),Sc-O(1)
        m=matrix.size();
        n=matrix[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==target) return true;
        //     }
        // }
        // return false;
        //better-Tc-O(m+n)
        // for(int i=0;i<m;i++){
        //     if(matrix[i][0]<=target && matrix[i][n-1]>=target){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==target) return true;
        //       }
        //     }
        // }
        // return false;
        //Binary search
        //Tc-O(m+logn)
        // bool res;
        // for(int i=0;i<m;i++){
        //     if(matrix[i][0]<=target && matrix[i][n-1]>=target){
        //         res=bs(matrix[i],0,n-1,target);
        //     }
        // }
        // return res;
        //optimal-Tc-O(log(m*n)),sc-O(log(m*n))
        int s=0,e=m*n-1;
        return bs(s,e,matrix,target);
    }
};