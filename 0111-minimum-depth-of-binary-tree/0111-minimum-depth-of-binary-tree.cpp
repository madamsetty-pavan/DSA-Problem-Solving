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
        int mindepth = INT_MAX;
        calMinDepth(root, 1, mindepth);
        if(mindepth == INT_MAX) return 0;
        return mindepth;
    }
    void calMinDepth(TreeNode* root, int depth, int &mindepth) {
        if(!root) return;
        if(!root->left && !root->right) {
            mindepth = min(depth, mindepth);
            return;
        }
        calMinDepth(root->left, depth+1, mindepth);
        calMinDepth(root->right, depth+1, mindepth);
    }
};