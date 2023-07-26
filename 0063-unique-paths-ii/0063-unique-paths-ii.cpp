// // Recursive with memo
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
//         vector<vector<int>> dp(m, vector<int>(n,-1));
        
//         if(obstacleGrid[m-1][n-1]==1) return 0;
//         return recurse(obstacleGrid, m, n, 0, 0, dp);
//     }
    
//     int recurse(vector<vector<int>>& obstacleGrid, int &m ,int &n,int i, int j,  vector<vector<int>> &dp) {
//         if(i == m-1 && j == n-1) {
//             return dp[i][j] = 1;
//         }
//         if(i>=m || j>=n) return 0;
//         if(obstacleGrid[i][j]==1) return dp[i][j] = 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int ans = 0;
//         ans += recurse(obstacleGrid, m, n,i+1, j, dp);
//         ans += recurse(obstacleGrid, m, n,i, j+1, dp);
//         return dp[i][j] = ans;
//     }
// };

// tabulation

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0; 
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i = m-1;i>=0;i--) {
            for(int j = n-1;j>=0;j--) {
                if(i==m-1 && j==n-1) dp[i][j] = 1;
                else {
                    if(obstacleGrid[i][j]==1) { dp[i][j]= 0 ;continue; }
                    long long ans = 0;
                    if(i+1<m) {
                        ans += dp[i+1][j];
                    }
                    if(j+1<n) {
                        ans += dp[i][j+1];
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][0];
    }
};


// Space optimised

