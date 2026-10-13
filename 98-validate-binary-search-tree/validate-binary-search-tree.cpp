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
    bool ivb(TreeNode* node,long int min,long int max){
        if(!node) return true;
        if(node->val<=min || node->val>=max) return false;
        return ivb(node->left,min,node->val) && ivb(node->right,node->val,max);
    }
    bool isValidBST(TreeNode* root) {
        //TC-O(n) SC-(1)
        return ivb(root,LONG_MIN,LONG_MAX);
    }
};