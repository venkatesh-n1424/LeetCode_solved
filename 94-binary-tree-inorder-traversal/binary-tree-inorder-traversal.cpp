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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        st.push(node);
        while(!st.empty()){
            if(node) node=node->left;
            if(node) st.push(node);
            else{
                TreeNode* res=st.top();
                st.pop();
                node=res->right;
                if(node) st.push(node);
                ans.emplace_back(res->val);
            }
        }
        
        return ans;
    }
};