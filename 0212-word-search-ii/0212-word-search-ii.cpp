class TrieNode {
    public:
        bool isEnd = false;
        TrieNode *children[26];
};
class Solution {
public:
    TrieNode* makeTrie(vector<string>&words) {
        TrieNode* root = new TrieNode();
        for(auto &word: words) {
            TrieNode* curr = root;
            for(auto &x:word) {
                if(curr->children[x-'a'] == NULL) curr->children[x-'a'] = new TrieNode();
                curr = curr->children[x-'a'];
            }
            curr->isEnd = true;
        }
        return root;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = makeTrie(words);
        vector<string> ans;
        unordered_set<string> st;
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(root->children[board[i][j]-'a'] != NULL) {
                    recurse(root, "", i, j, m , n, board, st, ans);
                }
            }
        }
        return ans;
    }
    
    void recurse(TrieNode* root, string str, int i, int j, int &m, int &n, vector<vector<char>>& board, unordered_set<string> &st, vector<string>&ans) {
        if(!root || i<0 || j<0 || i>=m | j>=n || board[i][j] == ' ') return;
        if(root->children[board[i][j]-'a'] != NULL) {
            str += board[i][j];
            root = root->children[board[i][j]-'a'];
            char c = board[i][j];
            if(root->isEnd == true) {
                if(st.find(str) == st.end()) {
                    ans.push_back(str);
                }
                st.insert(str);
            }
            board[i][j] = ' ';
            recurse(root, str, i+1, j, m, n, board, st, ans);
            recurse(root, str, i-1, j, m, n, board, st, ans);
            recurse(root, str, i, j+1, m, n, board, st, ans);
            recurse(root, str, i, j-1, m, n, board, st, ans);
            board[i][j] = c;
        }
    }
};
