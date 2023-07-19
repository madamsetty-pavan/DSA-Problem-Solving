class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        recurse(ans,board,n,0);
        return ans;
    }
    
    void recurse(vector<vector<string>>&ans, vector<string>&board, int n, int column) {
        if(column==n) {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++) {
            if(safe(board,i,column, n)) {
                board[i][column] = 'Q';
                recurse(ans,board,n,column+1);
                board[i][column] = '.';
            }
        }
    }
    
    bool safe(vector<string>&board, int row, int column, int n) {
        // check row wise
        for(int i=0;i<n;i++) {
            if(board[row][i]=='Q') return false;
        }
        
        // check column wise
        for(int i=0;i<n;i++) {
            if(board[i][column]=='Q') return false;
        }
        
        // check upper diagonally
        for(int i=row,j=column;i>=0&&j>=0;j--,i--) {
            if(board[i][j]=='Q') return false;
        }
       
        // check lower diagolnally
        for(int i=row,j=column;i<n&&j>=0;i++,j--) {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    
};