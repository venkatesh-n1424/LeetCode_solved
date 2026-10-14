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
    //vector<int> ans;
    // void inorder(TreeNode* root){
    //     if(!root) return;
    //     inorder(root->left);
    //     ans.emplace_back(root->val);
    //     inorder(root->right);
    // }
    int cnt=0,kth=-1;
    void inorder(TreeNode* root,int k){
        if(!root) return;
        inorder(root->left,k);
        cnt++;
        if(cnt==k){
            kth=root->val;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        //brute TC-O(n+nlogn) sc-O(n)
        //inorder(root);
        // sort(ans.begin(),ans.end());
        // return ans[k-1];
        //optimal-inorder of bst is always sorted TC-O(n) sc-O(height)
        inorder(root,k);
        return kth;
    }
};