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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        // only right child tree exists
        if(!root->left) return 1+minDepth(root->right);
        // only left child tree exists
        if(!root->right) return 1+minDepth(root->left);
        // both child exists
        return min(minDepth(root->left),minDepth(root->right))+1;
    } 
};