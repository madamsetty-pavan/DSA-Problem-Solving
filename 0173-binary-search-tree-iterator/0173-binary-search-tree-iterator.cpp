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
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode *curr;
    BSTIterator(TreeNode* root) {
        curr = root;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        curr = st.top();
        st.pop();
        int ans = curr->val;
        if(curr->right) curr = curr->right;
        else curr = NULL;
        while(curr) {
            st.push(curr);
            curr = curr ->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */