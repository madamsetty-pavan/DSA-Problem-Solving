static const int _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1] ==1) return -1;
        vector<int> directions = {-1,0,1 ,0,-1, 1, 1,-1, -1};
        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int,int>> qu;
        qu.push({0,0});
        visited[0][0] = 1;
        while(qu.size()) {
            ans++;
            int n1 = qu.size();
            for(int i=0;i<n1;i++) {
                auto front = qu.front();
                qu.pop();
                if(front.first == m-1 && front.second == n-1) return ans;
                for(int j=0;j<8;j++) {
                    int first = front.first + directions[j];
                    int second = front.second + directions[j+1];
                    if(first<m && second<n && first>=0 && second>=0 && grid[first][second] == 0 && visited[first][second] == 0){
                        qu.push({first,second});
                        visited[first][second] = 1;
                    }
                }
            }
        }
        return -1;
    }
};