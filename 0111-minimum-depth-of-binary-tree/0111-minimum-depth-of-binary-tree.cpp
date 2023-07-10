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
    // int minDepth(TreeNode* root) {
    //     //DFS Solution
    //     if(!root) return 0;
    //     // only right child tree exists
    //     if(!root->left) return 1+minDepth(root->right);
    //     // only left child tree exists
    //     if(!root->right) return 1+minDepth(root->left);
    //     // both child exists
    //     return min(minDepth(root->left),minDepth(root->right))+1;
    // } 


    int minDepth(TreeNode* root) {
        //BFS Solution
        if(!root)return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int depth = 1, n;
        
        while(!qu.empty()){
            n = qu.size();
            for(int i=0;i<n;i++) {
                TreeNode* root1 = qu.front();
                qu.pop();
                if(!root1->left && !root1->right) return depth;
                if(root1->left) qu.push(root1->left);
                if(root1->right) qu.push(root1->right);
            }
            depth++;
        }
        return -1;
    } 
};
