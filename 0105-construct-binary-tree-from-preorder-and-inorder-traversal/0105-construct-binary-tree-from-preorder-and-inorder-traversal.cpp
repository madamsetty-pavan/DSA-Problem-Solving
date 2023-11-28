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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderIndexMap;
        int n = inorder.size();
        for(int i=0;i<n;i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        int index = -1;
        return makeTree(0, n-1,inorderIndexMap, preorder, index);
    }
    
    TreeNode* makeTree(int startIndex, int endIndex, unordered_map<int,int> &inorderIndexMap, vector<int>& preorder, int &index) {
        if(startIndex>endIndex) return NULL;
        int presentIndex = ++index;
        TreeNode* root = new TreeNode(preorder[index]);
        if(startIndex == endIndex) {
            return root;
        }
        root -> left = makeTree(startIndex, inorderIndexMap[preorder[presentIndex]]-1, inorderIndexMap, preorder, index);
        root -> right = makeTree(inorderIndexMap[preorder[presentIndex]]+1, endIndex, inorderIndexMap, preorder, index);
        return root;
    }
};