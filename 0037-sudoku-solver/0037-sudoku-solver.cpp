class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solveSudoku(board, 0, 0,n);
    }


    bool solveSudoku(vector<vector<char>>& board, int row, int col, int& size) {
        if(row == size) {
            return true;
        }
        if(col == size) {
            return solveSudoku(board, row+1, 0, size);
        }
        if(board[row][col] != '.' ) {
            return solveSudoku(board, row, col+1, size);
        }

        for(char c='1'; c <= '9'; c++) {
            if(isFeasible(board, c, row, col, size)) {
                board[row][col] = c;
                if(solveSudoku(board,row,col+1,size)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    bool isFeasible(vector<vector<char>>&board, char value, int &row, int& col, int& size) {
        int i =0, j = 0;
        cout<<value<<endl;
        for(int i=0; i<size; i++){
            if(board[row][i] == value || board[i][col] == value) return false;
        }
        int initialR = row - row%3;
        int initialC = col - col%3;
        i = initialR; j = initialC;
        while(i<initialR + 3) {
            j = initialC;
            while(j<initialC+3) {
                if(board[i][j] == value) return false;
                j++;
            }
            i++;
        }
        return true;
    }
};