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

class Solution {
public:
    int minInsertions(string s) {
        int start = 0, end = s.size()-1;
        vector<vector<int>> dp(end+1, vector<int>(end+1, -1));
        return recurse(s, start, end, dp);
    }
    
    int recurse(string &s, int start, int end, vector<vector<int>> &dp) {
        if(start>=end) return dp[start][end]=0;
        if(dp[start][end] != -1) return dp[start][end];
        if(s[start] == s[end]) {
            return dp[start][end]=recurse(s, start +1, end -1,dp);
        }
        return dp[start][end]=(1 + min(recurse(s, start+1, end, dp), recurse(s, start, end-1, dp)));
    }
};