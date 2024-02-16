class Solution {
    private:
    vector<int> directions = {-1,0,1,0,-1};
    vector<vector<int>> fireGrid;
    vector<vector<int>> personGrid;
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        fireGrid = vector<vector<int>>(m, vector<int>(n,-1));
        personGrid = vector<vector<int>>(m, vector<int>(n,-1));
        
        bfs(grid, fireGrid, m, n, 1);
        bfs(grid, personGrid, m, n, 0);
     

        if(personGrid[m-1][n-1] == -1) return -1;
        if(fireGrid[m-1][n-1] == -1) return 1e9;
        if(personGrid[m-1][n-1]>fireGrid[m-1][n-1]) return -1;
        int diff =  fireGrid[m-1][n-1] - personGrid[m-1][n-1];
        if(personGrid[m-1][n-2] + diff < fireGrid[m-1][n-2] || personGrid[m-2][n-1] + diff < fireGrid[m-2][n-1]) return diff;
        return (diff - 1);
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>> &countGrid, int &m, int &n, int cell) {
        queue<pair<int,int>> qu;
        vector<vector<int>> visited(m, vector<int>(n,0));
        if(cell) {
              for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    if(grid[i][j] == 1) {
                        qu.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        else  {
            qu.push({0,0});
            visited[0][0] = 1;
        }
        int mins = -1;
        while(qu.size()){
            int size = qu.size();
            mins++;
            for(int c1=0;c1<size;c1++) {
                auto front = qu.front();
                qu.pop();
                countGrid[front.first][front.second] = mins;
                for(int j=0;j<4;j++) {
                    int first = front.first+directions[j];
                    int second = front.second+directions[j+1];
                    if(first<m && first>=0 && second<n && second>=0 && grid[first][second]==0 && visited[first][second]==0)  {
                        visited[first][second] = 1;
                        qu.push({first,second});
                    }
                }
            }
        }
    }
    
};