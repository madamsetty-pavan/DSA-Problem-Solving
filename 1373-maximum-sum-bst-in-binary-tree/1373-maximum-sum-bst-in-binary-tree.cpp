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
    int maxSumBST(TreeNode* root) {
        int maxSum = 0, sum=0, mini = INT_MAX, maxi = INT_MIN;
        checkIfBST(root, maxSum, sum, mini, maxi);
        return maxSum;
    }
    
    bool checkIfBST(TreeNode* &root, int &ans, int &sum, int &mini, int &maxi) {
        if(!root) return true;
        int left_max = INT_MIN, left_min = mini, right_max = maxi, right_min = INT_MAX, left_sum = 0,
            right_sum = 0;
        bool left = checkIfBST(root->left, ans, left_sum, left_min, left_max);
        bool right = checkIfBST(root->right, ans, right_sum, right_min, right_max);
        // cout<<root->val<<" "<<left_max<<" "<<left_min<<" "<<right_max<<" "<<right_min<<endl;
        if(left && right && left_max<root->val && root->val<right_min) {
            sum = left_sum+right_sum + root->val ;
            ans = max(ans, sum);
            maxi = max(right_max, root->val);
            mini = min(left_min, root->val);
            return true;
        }
        return false;
    }
};