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
    bool findTarget(TreeNode* root, int k) {
        vector<int> numbers;
        inorder(root, numbers);
        int i =0, j = numbers.size()-1, sum =0;
        while(i<j) {
            sum = numbers[i] + numbers[j];
            if(sum ==k) return true;
            else if(sum > k) j--;
            else i++;
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>&numbers) {
        if(!root) return;
        inorder(root->left, numbers);
        numbers.push_back(root->val);
        inorder(root->right, numbers);
    }
};