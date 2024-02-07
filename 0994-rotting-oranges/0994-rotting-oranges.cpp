class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> qu;
        vector<int> directions = {-1,0,1,0,-1};
        int fresh = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    qu.push({i,j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }       
        int ans = -1;
        while(!qu.empty()) {
            ans++;
            int sz = qu.size();
            while(sz--) {
                auto front = qu.front();
                qu.pop();
                for(int j=0;j<4;j++) {
                    int x = front.first + directions[j];
                    int y = front.second + directions[j+1];
                    if(x<n && y<m && x>=0 && y>= 0 && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        qu.push({x,y});
                    }
                }
            }
        }
        if(fresh>0) return -1;
        if(ans == -1) return 0;
        return ans;
    }
};