class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        return recurse(text1, text2, text1.size()-1, text2.size()-1, dp);
    }
    
    int recurse(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp) {
        if(index1<0 || index2<0) return 0;
        if(index1==0 && index2==0) {
            if(text1[index1] == text2[index2]) return dp[index1][index2]=1;
            return dp[index1][index2]=0;
        }
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + recurse(text1, text2, index1-1, index2-1,dp);
        }
        int ans = 0;
        ans = max(ans, recurse(text1, text2, index1-1, index2,dp));
        ans = max(ans, recurse(text1, text2, index1, index2-1,dp));
        return dp[index1][index2]=ans;
    }
};