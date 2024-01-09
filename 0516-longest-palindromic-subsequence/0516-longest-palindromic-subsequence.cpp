class Solution {
public:
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