// Top Down
// class Solution {
// public:
//     int minInsertions(string s) {
//         int start = 0, end = s.size()-1;
//         return recurse(s, start, end);
//     }
    
//     int recurse(string &s, int start, int end) {
//         if(start>=end) return 0;
//         if(s[start] == s[end]) {
//             return recurse(s, start +1, end -1);
//         }
//         return (1 + min(recurse(s, start +1, end), recurse(s, start, end-1)));
//     }
// };

// Top Down - optmised
// class Solution {
// public:
//     int minInsertions(string s) {
//         int start = 0, end = s.size()-1;
//         vector<vector<int>> dp(end+1, vector<int>(end+1, -1));
//         return recurse(s, start, end, dp);
//     }
    
//     int recurse(string &s, int start, int end, vector<vector<int>> &dp) {
//         if(start>=end) return dp[start][end]=0;
//         if(dp[start][end] != -1) return dp[start][end];
//         if(s[start] == s[end]) {
//             return dp[start][end]=recurse(s, start +1, end -1,dp);
//         }
//         return dp[start][end]=(1 + min(recurse(s, start+1, end, dp), recurse(s, start, end-1, dp)));
//     }
// };

// Another Approach - Find Longest palindrome subsequence.
// Subtract total length - longesgt palindrome subsequnce length
class Solution {
public:
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
    int longestPalindromeSubseq(string &text1) {
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(2, vector<int>(m+1,0));
        for(int i = 1;i <= n; i++) {
            for(int j = 1;j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                   dp[1][j] = 1 + dp[0][j-1];
                }  else {
                    dp[1][j] = max(dp[0][j], dp[1][j-1]);
                }
            }
            dp[0] = dp[1];
        }
        return dp[0][m];
    }
};