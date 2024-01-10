// Top down with memo
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         vector<vector<int>> dp(s.size(), vector<int>(t.size(),-1));
//         return recurse(s.size()-1, t.size()-1, s, t, dp);
//     }
    
//     int recurse(int i1, int i2, string &s, string &t, vector<vector<int>> &dp) {
//         if(i2<0)  {
//             return 1;
//         }
//         if(i1<0) return 0 ;
//         if(dp[i1][i2] !=-1) return dp[i1][i2];
//         if(s[i1] == t[i2]) {
//             return dp[i1][i2] = (recurse(i1-1, i2-1, s, t,dp) + recurse(i1-1, i2, s, t,dp));
//         }
//         return dp[i1][i2] =recurse(i1-1, i2, s, t,dp);
//     }
// };

// Bottom up
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n = s.size(), m = t.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1,0));
//         for(int i=0;i<=n;i++) {
//             dp[i][0] = 1;
//         }
//         for(int i=1;i<=n;i++) {
//             for(int j=1;j<=m;j++) {
//                 dp[i][j] = dp[i-1][j];
//                 if(s[i-1] == t[j-1]) {
//                     if(dp[i][j] >= INT_MAX - dp[i-1][j-1]) continue;
//                     dp[i][j] += dp[i-1][j-1];
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };

// Bottom up - Space optimised
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(2, vector<int>(m+1,0));
        for(int i=0;i<2;i++) {
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[1][j] = dp[0][j];
                if(s[i-1] == t[j-1]) {
                    if(dp[1][j] >= INT_MAX - dp[0][j-1]) continue;
                    dp[1][j] += dp[0][j-1];
                }
            }
            dp[0] = dp[1];
        }
        return dp[1][m];
    }
};