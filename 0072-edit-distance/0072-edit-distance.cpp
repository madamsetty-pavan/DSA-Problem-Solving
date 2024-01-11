// Top Down
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         return recurse(word1.size(), word2.size(), word1, word2);
//     }
//     int recurse(int index1, int index2, string &word1, string &word2) {
//         if(index1<0 || index2<0) return 0;
//         int ans = 1 + recurse(index1-1, index2, word1,word2);
//         if(word1[index1] == word2[index2]) {
//             return min(recurse(index1-1, index2-1, word1, word2), ans);
//         }
//         return ans;
//     }
// };


// Top Down with memo
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(word1.size(), vector<int>(word2.size(),-1));
//         return recurse(word1.size()-1, word2.size()-1, word1, word2,dp);
//     }
//     int recurse(int index1, int index2, string &word1, string &word2, vector<vector<int>> &dp) {
//         if(index1<0) return index2+1;
//         if(index2<0) return index1+1;
//         if(dp[index1][index2] !=-1) return dp[index1][index2];
//         if(word1[index1] == word2[index2]) {
//             return dp[index1][index2]=recurse(index1-1, index2-1, word1, word2, dp);
//         }
//         int ans = INT_MAX;
//         // Insert a new character at given index
//         ans = min(ans, 1+recurse(index1, index2-1, word1, word2, dp));
//         // Replace the given character
//         ans = min(ans, 1+recurse(index1-1, index2-1, word1, word2,dp));
//         // Delete the given character
//         ans = min(ans, 1+recurse(index1-1, index2, word1, word2, dp));
//         return dp[index1][index2]=ans;
//     }
// };




// Bottom up
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1,0));
//         for(int i=0;i<=n;i++) {
//             dp[i][0] = i;
//         }
//         for(int j=0;j<=m;j++) {
//             dp[0][j] = j;
//         }
//         for(int i=1;i<=n;i++) {
//             for(int j=1;j<=m;j++) {
//                 if(word1[i-1] == word2[j-1]) {
//                     dp[i][j] = dp[i-1][j-1];
//                 } else {
//                     // Insert a new character
//                     dp[i][j] = 1 + dp[i][j-1];
//                     // Replace a given character
//                     dp[i][j] = min(dp[i][j] , 1 + dp[i-1][j-1]);
//                     // Delete a given character
//                     dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };


// Bottom up - Space Optimised
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(2, vector<int>(m+1,0));
        dp[0][0] = 0;
        for(int j=0;j<=m;j++) {
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++) {
            dp[1][0] = i;
            for(int j=1;j<=m;j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[1][j] = dp[0][j-1];
                } else {
                    // Insert a new character
                    dp[1][j] = 1 + dp[1][j-1];
                    // Replace a given character
                    dp[1][j] = min(dp[1][j] , 1 + dp[0][j-1]);
                    // Delete a given character
                    dp[1][j] = min(dp[1][j], 1 + dp[0][j]);
                }
            }
            dp[0] = dp[1];
        }
        return dp[0][m];
    }
};


