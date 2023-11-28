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

#define INT_MIN -1e5
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findSum(root, ans);
        return ans;
    }
    
    int findSum(TreeNode* &root, int &ans) {
        int left = INT_MIN, right = INT_MIN;
        if(root->left) left = findSum(root->left, ans);
        if(root->right) right = findSum(root->right, ans);
        int maxValue = root->val;
        if(left != INT_MIN && right!= INT_MIN) {
            maxValue = max(maxValue, root->val+left+right);
        }
        if(left!=INT_MIN) {
            maxValue = max(maxValue, root->val + left);
        } 
        if(right != INT_MIN) {
            maxValue = max(maxValue, root->val + right);
        }
        ans = max(maxValue, ans);
        if (root->val + left > 0 && root->val+left > root->val+right) {
            return root->val +left;
        } else if(root->val +right > 0 && root->val+left < root->val+right) {
            return root->val + right;
        }
        if(root->val > 0) return root->val;
        return INT_MIN;
    }
};