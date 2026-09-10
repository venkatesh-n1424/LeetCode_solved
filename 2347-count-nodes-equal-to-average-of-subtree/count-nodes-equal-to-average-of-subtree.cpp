/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res=0;
    pair<int,int> dfs(TreeNode* node){
        if(!node) return make_pair(0,0);
        pair<int,int> lval_lcount = dfs(node->left);
        pair<int,int> rval_rcount = dfs(node->right);
        int nval = lval_lcount.first+rval_rcount.first+node->val;
        int ncount = lval_lcount.second+rval_rcount.second+1;
        if(nval/ncount==node->val) res++;
        return make_pair(nval,ncount);
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> r=dfs(root);
        return res;
    }
};