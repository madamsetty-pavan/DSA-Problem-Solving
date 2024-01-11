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
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n==0) return m;
        if(m==0) return n;
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(),-1));
        return recurse(word1.size()-1, word2.size()-1, word1, word2,dp);
    }
    int recurse(int index1, int index2, string &word1, string &word2, vector<vector<int>> &dp) {
        if(index1<0) return index2+1;
        if(index2<0) return index1+1;
        if(dp[index1][index2] !=-1) return dp[index1][index2];
        if(word1[index1] == word2[index2]) {
            return dp[index1][index2]=recurse(index1-1, index2-1, word1, word2, dp);
        }
        int ans = INT_MAX;
        // Insert a new character at given index
        ans = min(ans, 1+recurse(index1, index2-1, word1, word2, dp));
        // Replace the given character
        ans = min(ans, 1+recurse(index1-1, index2-1, word1, word2,dp));
        // Delete the given character
        ans = min(ans, 1+recurse(index1-1, index2, word1, word2, dp));
        return dp[index1][index2]=ans;
    }
};