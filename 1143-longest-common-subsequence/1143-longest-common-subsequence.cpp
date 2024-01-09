// Top Down with memo
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
//         return recurse(text1, text2, text1.size()-1, text2.size()-1, dp);
//     }
    
//     int recurse(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp) {
//         if(index1<0 || index2<0) return 0;
//         if(index1==0 && index2==0) {
//             if(text1[index1] == text2[index2]) return dp[index1][index2]=1;
//             return dp[index1][index2]=0;
//         }
//         if(dp[index1][index2] != -1) return dp[index1][index2];
//         if(text1[index1] == text2[index2]) {
//             return dp[index1][index2] = 1 + recurse(text1, text2, index1-1, index2-1,dp);
//         }
//         int ans = 0;
//         ans = max(ans, recurse(text1, text2, index1-1, index2,dp));
//         ans = max(ans, recurse(text1, text2, index1, index2-1,dp));
//         return dp[index1][index2]=ans;
//     }
// };

// Bottom up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),0));
        int n = text1.size(), m = text2.size();
        for(int i = 0;i < n; i++) {
            for(int j = 0;j < m; j++) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1;
                    if(i-1>=0 && j-1>=0) dp[i][j] += dp[i-1][j-1];
                }  else {
                    if(i-1>=0) dp[i][j] = max(dp[i-1][j], dp[i][j]);
                    if(j-1>=0) dp[i][j] = max(dp[i][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};


















