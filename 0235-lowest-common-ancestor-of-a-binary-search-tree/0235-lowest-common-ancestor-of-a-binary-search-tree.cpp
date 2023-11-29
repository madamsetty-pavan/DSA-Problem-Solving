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
    int large = 0;
    int small = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        large = max(p->val, q->val);
        small = min(p->val, q->val);
        return checkLCA(root);
    }
    
    TreeNode* checkLCA(TreeNode* &root) {
        if(root->val> large) {
            return checkLCA(root->left);
        } else if(root->val < small) {
            return checkLCA(root->right);
        }
        return root;
    }
 };