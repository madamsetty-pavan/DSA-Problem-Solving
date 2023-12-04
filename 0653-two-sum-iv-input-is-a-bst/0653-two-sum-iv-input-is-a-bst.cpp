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
// Method 1: O(n) Time complexity, O(n) - Space complexity
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         vector<int> numbers;
//         inorder(root, numbers);
//         int i =0, j = numbers.size()-1, sum =0;
//         while(i<j) {
//             sum = numbers[i] + numbers[j];
//             if(sum == k) return true;
//             else if(sum > k) j--;
//             else i++;
//         }
//         return false;
//     }
    
//     void inorder(TreeNode* &root, vector<int>&numbers) {
//         if(!root) return;
//         if(root->left) inorder(root->left, numbers);
//         numbers.push_back(root->val);
//         if(root->right) inorder(root->right, numbers);
//     }
// };

// Method 2: O(n) Time Complexity, O(H) - Space complexity
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* curr;
    void initialise(TreeNode* &root, bool isLeft = true) {
        if(!root) return;
        curr = root;
        while(curr) {
            st.push(curr);
            if(isLeft) curr = curr->left; 
            else curr = curr->right;
        }
    }
    int getNext(bool isLeft = true) {
        curr = st.top();
        st.pop();
        int ans = curr->val;
        if(isLeft) {
            if(curr->right) curr = curr->right;
            else curr = NULL;
        } else {
            if(curr->left) curr = curr->left;
            else curr = NULL;
        }
        while(curr) {
            st.push(curr);
            if(isLeft) curr = curr->left; 
            else curr = curr ->right;
        }
        return ans;
    }
};


class Solution {
public:
    BSTIterator leftPtr, rightPtr;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        leftPtr.initialise(root);
        rightPtr.initialise(root, false);
        int left = leftPtr.getNext(), right = rightPtr.getNext(false), sum;
        while(left<right) {
            sum = left + right;
            if(sum ==k) return true;
            else if(sum<k) left = leftPtr.getNext();
            else right = rightPtr.getNext(false);
        }
        return false;
    }
};