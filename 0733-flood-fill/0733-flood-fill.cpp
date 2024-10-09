class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int directions[5] = {0,1,0,-1,0};
        int n = image.size(), m = image[0].size();
        if (sr>=n || sr<0 || sc >= m || sc<0 || image[sr][sc]==color) return image;
        int intColor = image[sr][sc];
        queue<pair<int, int>> qu;
        qu.push({sr,sc});
        while(qu.size()) {
            int size = qu.size();
            for(int i=0;i<size;i++) {
                auto front = qu.front();
                qu.pop();
                image[front.first][front.second] = color;
                for(int j=0;j<4;j++) {
                    auto nextX = front.first + directions[j];
                    auto nextY = front.second + directions[j+1];
                    if(nextX>=0 && nextX<n && nextY>=0 && nextY < m && image[nextX][nextY]==intColor) {
                        qu.push({nextX,nextY});
                    }
                }
            }
        }
        return image;
    }
};