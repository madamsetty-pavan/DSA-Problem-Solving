class Solution {
public:
    static constexpr int directions[] = {0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> qu;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (mat[i][j]==0) {
                    qu.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        while(qu.size()) {
            int size = qu.size();
            for(int i=0;i<size;i++) {
                auto front = qu.front();
                qu.pop();
                for (int j=0; j<4; j++) {
                    int nextX = front.first + directions[j];
                    int nextY = front.second + directions[j+1];
                    if(nextX>=0 && nextX<n && nextY>=0 && nextY<m) {
                        if (ans[nextX][nextY] == INT_MAX) {
                            ans[nextX][nextY] = ans[front.first][front.second] + 1;
                            qu.push({nextX,nextY});
                        }
                    }
                }
            }
        }
        return ans;
    }
};