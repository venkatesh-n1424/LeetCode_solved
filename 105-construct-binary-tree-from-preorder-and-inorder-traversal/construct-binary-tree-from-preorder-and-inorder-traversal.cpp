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
     TreeNode* build(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie,unordered_map<int,int>& inMap){
        if(ps>pe || is>ie) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int in=inMap[preorder[ps]];
        int inl=in-is;
        int inr=ie-in;
        root->left=build(preorder,inorder,ps+1,ps+inl,is,in-1,inMap);
        root->right=build(preorder,inorder,pe-inr+1,pe,in+1,ie,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        int n=preorder.size();
        for(int i=0;i<inorder.size();i++) inMap[inorder[i]]=i;
        return build(preorder,inorder,0,n-1,0,n-1,inMap);
    }
};