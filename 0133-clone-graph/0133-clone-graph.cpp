/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> mp;
        Node* newGraph = new Node(node->val);
        mp[node] = newGraph;
        queue<Node*> qu;
        unordered_set<Node*> visited; 
        visited.insert(node);
        qu.push(node);
        while(!qu.empty()) {
            auto front = qu.front();
            qu.pop();
            for(auto &x: front->neighbors) {
                if(mp.find(x) == mp.end()) {
                    mp[x] = new Node(x->val);
                }
                mp[front]->neighbors.push_back(mp[x]);
                if(visited.find(x) == visited.end()) {
                    qu.push(x);
                    visited.insert(x);
                }
            }
        }
        return newGraph;
    }
};