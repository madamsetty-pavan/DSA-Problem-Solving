class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string str(n,'.');
        vector<string> board(n,str);
        findQueens(board, ans, 0, n);
        return ans;
    }

    void findQueens(vector<string>&board, vector<vector<string>>&ans, int col, int& n) {
        if(col == n){
            ans.push_back(board);
            return;
        } 
        for(int i=0;i<n;i++) {
            if(isSafe(board, i, col, n)) {
                board[i][col] = 'Q';
                findQueens(board, ans, col+1, n);
                board[i][col] = '.';
            }
        }
    }

    bool isSafe(vector<string>& board, int row, int col, int& n) {
        for (int i=0; i<n; i++) {
            if(board[row][i] == 'Q' || board[i][col] == 'Q') return false;
        }
        for(int i=0;i<n;i++) {
            if(row+i<n) {
                if(col-i>=0 && board[row+i][col-i] == 'Q') return false; 
            } 
            if(row-i >=0) {
                if(col-i>=0 && board[row-i][col-i] == 'Q') return false;
            }
        }
        return true;
    }

};