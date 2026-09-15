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
    void iot(TreeNode* root){
        if(!root) return;
        iot(root->left);
        res.emplace_back(root->val);
        iot(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        iot(root);
        return res;
    }
};