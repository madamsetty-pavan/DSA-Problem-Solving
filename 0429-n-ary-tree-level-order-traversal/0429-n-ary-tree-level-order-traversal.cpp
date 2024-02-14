/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()) {
            vector<int> temp;
            int n = qu.size();
            for(int i=0;i<n;i++) {
                Node* top = qu.front();
                qu.pop();
                temp.push_back(top->val);
                for(int j=0;j<top->children.size();j++) {
                    qu.push(top->children[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};