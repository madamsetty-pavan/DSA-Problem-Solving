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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        populateParents(root, parent, NULL);
        queue<TreeNode*> qu;
        qu.push(target);
        int n;
        vector<int> ans;
        unordered_set<TreeNode*> seen;
        seen.insert(target);
        while(!qu.empty()) {
            n = qu.size();
            for(int i=0;i<n;i++) {
                TreeNode* curr = qu.front();
                qu.pop();
                if(k==0) ans.push_back(curr->val);
                if(curr->left && seen.find(curr->left)==seen.end()) {
                    seen.insert(curr->left);
                    qu.push(curr->left);
                }
                if(curr->right && seen.find(curr->right)==seen.end()) {
                    seen.insert(curr->right);
                    qu.push(curr->right);
                }
                if(parent[curr] && seen.find(parent[curr])==seen.end()) {
                    seen.insert(parent[curr]);
                    qu.push(parent[curr]);
                }
            }
            if(k==0) return ans;
            k--;
        }
        return {};
    }
    
    void populateParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> & parentMap, TreeNode* parent) {
        if(!root) return;
        populateParents(root->left, parentMap, root);
        populateParents(root->right,parentMap, root);
        parentMap[root] = parent;
    }
};