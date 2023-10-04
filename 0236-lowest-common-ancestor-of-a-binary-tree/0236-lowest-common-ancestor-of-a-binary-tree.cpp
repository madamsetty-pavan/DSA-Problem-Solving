/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        makePath(root, p, path1);
        makePath(root,q,path2);
        int i = path1.size()-1, j = path2.size()-1;
        while(i>=0 && j>=0 && path1[i]==path2[j]) {
            i--;
            j--;
        }
        if(i<0) return path1[0];
        else if(j<0) return path2[0];
        return path1[i+1];
    }
    
    bool makePath(TreeNode* root, TreeNode* p, vector<TreeNode*> &path) {
        if(!root) return false;
        if(root == p || makePath(root->left,p,path) || makePath(root->right,p,path)) {
            path.push_back(root);
            return true;
        } 
        return false;
    }
};