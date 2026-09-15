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
    vector<int> postorderTraversal(TreeNode* root) {
        //two stack
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            if(root->left) st1.push(root->left);
            if(root->right) st1.push(root->right);
            st2.push(root);
        }
        while(!st2.empty()){
            ans.emplace_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};