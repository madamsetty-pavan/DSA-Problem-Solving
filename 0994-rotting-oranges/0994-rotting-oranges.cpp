class Solution {
public:
    struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
    static constexpr int directions[5] = {-1,0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1, n = grid.size(), m = grid[0].size();
        unordered_set<pair<int,int>, pair_hash> st;
        queue<pair<int,int>> qu;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (grid[i][j] == 1) {
                    st.insert({i,j});
                } else if(grid[i][j] == 2) {
                    qu.push({i,j});
                }
            }
        }
        if(st.size() == 0) return 0;
        if(qu.size() == 0) return -1;
        while(qu.size()) {
            int qSize = qu.size();
            for(int i=0;i<qSize;i++) {
                auto curr = qu.front();
                qu.pop();
                for(int j=0;j<4;j++) {
                    int nextX = curr.first + directions[j];
                    int nextY = curr.second + directions[j+1];
                    if (st.find({nextX,nextY}) != st.end()) {
                       st.erase({nextX,nextY});
                       qu.push({nextX, nextY}); 
                    }
                }
            }
            ans++;
        }
        if(st.size() !=0 ) return -1;
        return ans;
    }
};