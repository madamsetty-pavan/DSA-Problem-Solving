class TrieNode {
    public:
        bool isEnd;
        vector<TrieNode*> children;
        TrieNode() {
            isEnd = false;
            children = vector<TrieNode*>(26,NULL);   
        }
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
    
//     void traverse(TrieNode* root) {
//         for(int i=0;i<26;i++) {
//             if(root->children[i] != NULL ){
//                 cout<<static_cast<char>(i+'a')<<" ";
//                 if(root->isEnd) cout<<"END OF WORD"<<endl;
//                 traverse(root->children[i]);
//             }
//         }
        
//     }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = makeTrie(words);
        // for(int i=0;i<26;i++) {
        //     cout<<static_cast<char>(i+'a')<<" "<<root->children[i]<<endl;
        // }
        // cout<<endl;
        //traverse(root);
        vector<string> ans;
        unordered_set<string> st;
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                // cout<<board[i][j]<<" "<<root->children[board[i][j]-'a']<<endl;
                if(root->children[board[i][j]-'a'] != NULL) {
                    // cout<<board[i][j]<<endl;
                    string str = "";
                    recurse(root, str, i, j, m , n, board, st);
                }
            }
        }
        for(auto &x:st) {ans.push_back(x);}
        return ans;
    }
    
    void recurse(TrieNode* root, string str, int i, int j, int &m, int &n, vector<vector<char>>& board, unordered_set<string> &st) {
        if(!root || i<0 || j<0 || i>=m | j>=n || board[i][j] == ' ') return;
        if(root->children[board[i][j]-'a'] != NULL) {
            str += board[i][j];
            // cout<<str<<endl;
            root = root->children[board[i][j]-'a'];
            char c = board[i][j];
            if(root->isEnd == true) {
                st.insert(str);
            }
            board[i][j] = ' ';
            recurse(root, str, i+1, j, m, n, board, st);
            recurse(root, str, i-1, j, m, n, board, st);
            recurse(root, str, i, j+1, m, n, board, st);
            recurse(root, str, i, j-1, m, n, board, st);
            board[i][j] = c;
        }
    }
};
