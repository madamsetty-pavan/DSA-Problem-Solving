// Recursive

// class Solution {
// public:
    
//     long long recurse(vector<vector<int>>& grid, int i, int j1, int j2)  {
//         if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
//         if(i==grid.size()-1) {
//             if(j1==j2) return grid[i][j1];
//             else return grid[i][j1]+grid[i][j2];
//         }
//         long long ans = 0;
//         for(int l1=-1;l1<2;l1++)  {
//             for(int l2=-1;l2<2;l2++) {
//                 if(j1 == j2) ans = max(ans, grid[i][j1]+recurse(grid,i+1,j1+l1,j2+l2));
//                 else ans = max(ans, grid[i][j1]+grid[i][j2]+recurse(grid,i+1,j1+l1,j2+l2));
//             }
//         }
//         return ans;
//     }
    
//     int cherryPickup(vector<vector<int>>& grid) {
//         return recurse(grid,0,0,grid[0].size()-1);
//     }
// };

// Recurse + Memo
class Solution {
public:
    
    long long recurse(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<long long>>> &dp)  {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1) {
            if(j1==j2) return dp[i][j1][j2]=grid[i][j1];
            else return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        long long ans = 0;
        for(int l1=-1;l1<2;l1++)  {
            for(int l2=-1;l2<2;l2++) {
                if(j1 == j2) ans = max(ans, grid[i][j1]+recurse(grid,i+1,j1+l1,j2+l2,dp));
                else ans = max(ans, grid[i][j1]+grid[i][j2]+recurse(grid,i+1,j1+l1,j2+l2,dp));
            }
        }
        return dp[i][j1][j2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<long long>>> dp(grid.size(),vector<vector<long long>>(grid[0].size(),vector<long long>(grid[0].size(),-1)));
        return recurse(grid,0,0,grid[0].size()-1,dp);
    }
};