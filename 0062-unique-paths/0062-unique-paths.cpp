// Recursion with memo
// class Solution {
// public:
//     int recurse(int i, int j, int m, int n,  vector<vector<int>> &dp) {
//         if(i==m && j==n) { return dp[i][j] = 1;}
//         if(i>m || j>n || i<0 || j<0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int ans = recurse(i+1,j,m,n,dp);
//         ans += recurse(i,j+1,m,n,dp);
//         return dp[i][j] = ans;
//     }
    
    
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return recurse(0,0,m-1,n-1,dp);
//     }
// };


// tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1] = 1;
        int ans = 0;
        for(int i = m-1;i>=0;i--) {
            for(int j = n-1;j>=0;j--) {
                if(i==m-1 && j == n-1) continue;
                ans = 0;
                if(i+1<m) {
                    ans += dp[i+1][j];
                }
                if(j+1<n) {
                    ans += dp[i][j+1];
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

