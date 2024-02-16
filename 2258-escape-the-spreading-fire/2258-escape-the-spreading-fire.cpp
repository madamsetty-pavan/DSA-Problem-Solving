class Solution {
    private:
    vector<int> directions = {-1,0,1,0,-1};
    vector<vector<pair<int,int>>> paths;
    vector<vector<int>> fireGrid;
    vector<vector<int>> personGrid;
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        vector<pair<int,int>> path;
        fireGrid = vector<vector<int>>(m, vector<int>(n,-1));
        personGrid = vector<vector<int>>(m, vector<int>(n,-1));
        bfs(grid, fireGrid, m, n, 1);
        bfs(grid, personGrid, m, n, 0);
        double ans = INT_MIN;
        // findAllPaths(grid, visited, 0, 0, m, n, ans, 1e9, 0);
        
        // cout<<"paths are of size "<<paths.size()<<endl;
        // for(auto &x:paths) {
        //     for(int i=0;i<x.size();i++) {
        //         cout<<x[i].first<<","<<x[i].second<<"  ";
        //     }
        //     cout<<endl;
        // }
        
        
        
//         cout<<"Fire Grid is "<<endl;
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 cout<<fireGrid[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//         cout<<"Person Grid is "<<endl;
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 cout<<personGrid[i][j]<<" ";
//             }
//             cout<<endl;
        // }
        if(personGrid[m-1][n-1] == -1) return -1;
        if(fireGrid[m-1][n-1] == -1) return 1e9;
        if(personGrid[m-1][n-1]>fireGrid[m-1][n-1]) return -1;
        int diff =  fireGrid[m-1][n-1] - personGrid[m-1][n-1];
        if(personGrid[m-1][n-2] + diff < fireGrid[m-1][n-2] || personGrid[m-2][n-1] + diff < fireGrid[m-2][n-1]) return diff;
        return (diff - 1);
        
//         double ans = INT_MIN;
//         for(auto &trav: paths){
//             double temp_ans = 1e9, k = trav.size(), flag = 0;
//             for(int i=0;i<k;i++) {
//                 double fireTime = fireGrid[trav[i].first][trav[i].second];
//                 double myTime = i;
//                 // If Fire never came in this cell -> 10^9 mins
//                 if(fireTime == -1) {
//                     temp_ans = temp_ans<1e9? temp_ans:1e9;
//                 } else if(fireTime<=myTime && trav[i].first != m-1 && trav[i].second != n-1){
//                     flag = 1;
//                     break;
//                 } else {
//                     if(trav[i].first == m-1 && trav[i].second == n-1) temp_ans = min(temp_ans, fireTime-i);
//                     else temp_ans = min(temp_ans, fireTime-1-i);
//                 }
                   
//             }
//             if(flag == 0) {
//                 ans = max(ans, temp_ans);
//             }
//         }
        // cout<<ans<<endl;
        if(ans == INT_MIN) return -1;
        return ans;
    }
    
    void findAllPaths(vector<vector<int>>& grid, vector<vector<int>>&visited, int x, int y, int& m, int& n, double &ans, double temp_ans, double count) {
        // cout<<ans<<" "<<temp_ans<<endl;
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y] != 0 || visited[x][y] == 1) return;
        // path.push_back({x,y});
        int fireTime = fireGrid[x][y];
        if(x==m-1 && y==n-1) {
            if(fireTime == -1) ans = max(ans, 1e9);
            else {
                temp_ans = min(temp_ans, fireTime-count);
                ans = max(ans, temp_ans);   
            }
            return;
        }
        if(fireTime == -1) temp_ans = temp_ans<1e9? temp_ans:1e9;
        else if(fireTime <= count) return;
        else {
            temp_ans = min(temp_ans, fireTime-1-count);
        }
        // cout<<temp_ans<<endl;
        visited[x][y] = 1;
        for(int i=0;i<4;i++) {
            findAllPaths(grid,visited,x+directions[i], y+directions[i+1], m, n, ans, temp_ans,count+1);
        }
        visited[x][y] = 0;
    }
    
//     void bfsForFire(vector<vector<int>>& grid, vector<vector<int>> &fireGrid, int &m, int &n) {
//         queue<pair<int,int>> qu;
//         vector<vector<int>> visited(m, vector<int>(n,0));
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 if(grid[i][j] == 1) {
//                     qu.push({i,j});
//                     visited[i][j] = 1;
//                 }
//             }
//         }
//         int mins = -1;
//         while(qu.size()){
//             int size = qu.size();
//             mins++;
//             for(int c1=0;c1<size;c1++) {
//                 auto front = qu.front();
//                 qu.pop();
//                 fireGrid[front.first][front.second] = mins;
//                 for(int j=0;j<4;j++) {
//                     int first = front.first+directions[j];
//                     int second = front.second+directions[j+1];
//                     if(first<m && first>=0 && second<n && second>=0 && grid[first][second]==0 && visited[first][second]==0)  {
//                         visited[first][second] = 1;
//                         qu.push({first,second});
//                     }
//                 }
//             }
//         }
//     }
     
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