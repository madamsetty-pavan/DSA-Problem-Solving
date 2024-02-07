class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> qu;
        vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    qu.push({i,j});
                }
            }
        }       
        int ans = 0;
        while(!qu.empty()) {
            ans++;
            int n1 = qu.size();
            for(int i=0;i<n1;i++) {
                auto front = qu.front();
                qu.pop();
                //cout<<front.first<<" "<<front.second<<" ";
                for(int j=0;j<4;j++) {
                    int x = front.first + directions[j][0];
                    int y = front.second + directions[j][1];
                    if(x<n && y<m && x>=0 && y>= 0 && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        qu.push({x,y});
                    }
                }
            }
            //cout<<endl;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans>0?ans-1:0;
    }
};