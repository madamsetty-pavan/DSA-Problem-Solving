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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findSum(root, ans);
        return ans;
    }
    
    int findSum(TreeNode* &root, int &ans) {
        if(!root) return 0;
        int left = findSum(root->left, ans);
        int right = findSum(root->right, ans);
        
        ans = max(ans, root->val+left+right);
        int sum = root->val + max(left, right);
        return sum>0? sum: 0;
    }
    
    int max(int a, int b) {
        if(a>=b) return a;
        return b;
    }
};