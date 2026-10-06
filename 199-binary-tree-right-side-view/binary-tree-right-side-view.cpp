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
    vector<int> res;
    void prerev(TreeNode* root,int level){
        if(!root) return;
        if(level==res.size()) res.emplace_back(root->val);
        prerev(root->right,level+1);
        prerev(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        prerev(root,0);
        return res;
    }
};