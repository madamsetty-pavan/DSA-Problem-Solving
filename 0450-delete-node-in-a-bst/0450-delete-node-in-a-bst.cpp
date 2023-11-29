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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key) {
            if(!root->left && !root->right) {
                return NULL;
            } else if(!root->right) {
                return root->left;
            } else {
                TreeNode* temp = root->right, *prev = root;
                while(temp->left) {
                    prev = temp;
                    temp = temp->left;
                }
                if(temp != root->right) {
                    if(temp->right) prev->left = temp->right;
                    else prev -> left = NULL;
                    temp -> left = root->left;
                    temp -> right = root->right;
                    return temp;
                } else {
                    temp->left = root->left;
                    return temp;
                }
            }
        }
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
    
};