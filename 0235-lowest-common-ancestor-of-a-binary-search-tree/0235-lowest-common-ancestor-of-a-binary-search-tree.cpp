/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root) return root;
//         if(!root || root== p || root== q) return root;
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//         if(left && right) return root;
//         if(left) return left;
//         return right;
//     }
//  };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int large = max(p->val, q->val);
        int small = min(p->val, q->val);
        return checkLCA(root, large, small);
    }
    
    TreeNode* checkLCA(TreeNode* &root, int &large, int &small) {
        if(root->val> large) {
            return checkLCA(root->left, large,small);
        } else if(root->val < small) {
            return checkLCA(root->right, large, small);
        }
        return root;
    }
 };