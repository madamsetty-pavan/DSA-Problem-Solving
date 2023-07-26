// Recursive solution
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int ans = INT_MAX;
//         for(int i=0;i<matrix.size();i++) {
//             ans = min(ans, recurse(matrix,0,i));
//         }
//         return ans;
//     }
    
//     int recurse(vector<vector<int>>& matrix, int i, int j) {
//         if(i==matrix.size()-1) return matrix[i][j];
//         int left = INT_MAX;
//         if(j-1>=0) left = recurse(matrix, i+1,j-1);
//         int middle = recurse(matrix, i+1, j);
//         int right = INT_MAX;
//         if(j+1<matrix[0].size()) right = recurse(matrix, i+1,j+1);
//         return matrix[i][j] + min(left, min(right,middle));
//     }
// };


// // Recursive with memo
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int ans = INT_MAX;
//         vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
//         for(int i=0;i<matrix.size();i++) {
//             ans = min(ans, recurse(matrix,0,i,dp));
//         }
//         return ans;
//     }
    
//     int recurse(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>& dp) {
//         if(i==matrix.size()-1) return matrix[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int left = INT_MAX;
//         if(j-1>=0) left = recurse(matrix, i+1,j-1,dp);
//         int middle = recurse(matrix, i+1, j,dp);
//         int right = INT_MAX;
//         if(j+1<matrix[0].size()) right = recurse(matrix, i+1,j+1,dp);
//         return dp[i][j] = (matrix[i][j] + min(left, min(right,middle)));
//     }
// };


// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1; i>=0; i-- ) {
            for(int j = n-1; j>=0; j--) {
                if(i==n-1) dp[i][j]=matrix[i][j];
                else {
                    int left = INT_MAX;
                    if(j-1>=0) left = dp[i+1][j-1];
                    int right = INT_MAX;
                    if(j+1<n) right = dp[i+1][j+1];
                    int middle = dp[i+1][j];
                    dp[i][j] = matrix[i][j] + min(left, min(right,middle));
                }
            }
        }
        for(int i=0;i<n;i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};



