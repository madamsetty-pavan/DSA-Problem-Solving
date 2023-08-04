class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j] == word[0]) {
                    if(recurse(board, word, i, j, 0, visited)) return true;
                }
            }
        }
        return false;
    }
    
    bool recurse(vector<vector<char>>&board, string &word, int i, int j, int index, vector<vector<int>> &visited) {
        if(index == word.size()) {
            return true;
        }
        if(i>=board.size() || j>=board[i].size() || i<0 || j<0) return false;
        if(word[index]!=board[i][j] || visited[i][j]) return false;
        visited[i][j]= 1;
        bool down = recurse(board,word, i+1,j,index+1,visited);
        bool right = recurse(board,word,i,j+1,index+1,visited);
        bool up = recurse(board,word, i-1,j,index+1,visited);
        bool left = recurse(board,word, i,j-1,index+1,visited);
        if(down || up|| right || left) return true;
        visited[i][j]= 0;
        return false;
    }
    
};