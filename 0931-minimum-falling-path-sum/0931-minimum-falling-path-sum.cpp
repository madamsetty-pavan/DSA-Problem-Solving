// Top Down
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         int mini = INT_MAX;
//         for(int i=0;i<m;i++) {
//             mini = min(mini, recurse(0,i,matrix,m,n));
//         }
//         return mini;
//     }
    
//     int recurse(int i, int j, vector<vector<int>>& matrix, int &m, int &n) {
//         if(i>=m || j>=n || j<0) return INT_MAX;
//         if(i==m-1) return matrix[i][j];
//         return matrix[i][j] + min(recurse(i+1,j-1,matrix,m,n), min(recurse(i+1,j,matrix,m,n), recurse(i+1,j+1,matrix,m,n)));
//     }
// };


// // Top Down - Memo
// But will get TLE for this too
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,-1));
//         int mini = INT_MAX;
//         for(int i=0;i<m;i++) {
//             mini = min(mini, recurse(0,i,matrix,m,n,dp));
//         }
//         return mini;
//     }
    
//     int recurse(int i, int j, vector<vector<int>>& matrix, int &m, int &n, vector<vector<int>>&dp) {
//         if(i>=m || j>=n || j<0) return INT_MAX;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(i==m-1) return dp[i][j]=matrix[i][j];
//         return dp[i][j]=matrix[i][j] + min(recurse(i+1,j-1,matrix,m,n, dp), min(recurse(i+1,j,matrix,m,n,dp), recurse(i+1,j+1,matrix,m,n,dp)));
//     }
// };


// Bottom up
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> dp(m, vector<int>(n,-1));
//         int ans = INT_MAX;
//         for(int i=m-1;i>=0;i--) {
//             for(int j=n-1;j>=0;j--) {
//                 if(i==m-1) {
//                     dp[i][j] = matrix[i][j];
//                 } else {
//                     dp[i][j] = dp[i+1][j];
//                     if(j-1>=0) {
//                         dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
//                     }
//                     if(j+1<m) {
//                         dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
//                     }
//                     dp[i][j] += matrix[i][j];
//                     if(i==0) {
//                         ans = min(ans, dp[i][j]);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


// Bottom up - Space Optimised
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(n,-1));
        int ans = INT_MAX;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(i==m-1) {
                    dp[0][j] = matrix[i][j];
                    
                } else {
                    dp[0][j] = dp[1][j];
                    if(j-1>=0) {
                        dp[0][j] = min(dp[0][j], dp[1][j-1]);
                    }
                    if(j+1<m) {
                        dp[0][j] = min(dp[0][j], dp[1][j+1]);
                    }
                    dp[0][j] += matrix[i][j];
                }
                if(i==0) {
                    ans = min(ans, dp[0][j]);
                }
            }
            dp[1] = dp[0];
        }
        return ans;
    }
};
