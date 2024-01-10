class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(),-1));
        return recurse(s.size()-1, t.size()-1, s, t, dp);
    }
    
    int recurse(int i1, int i2, string &s, string &t, vector<vector<int>> &dp) {
        if(i2<0)  {
            return 1;
        }
        if(i1<0) return 0 ;
        if(dp[i1][i2] !=-1) return dp[i1][i2];
        if(s[i1] == t[i2]) {
            return dp[i1][i2] = (recurse(i1-1, i2-1, s, t,dp) + recurse(i1-1, i2, s, t,dp));
        }
        return dp[i1][i2] =recurse(i1-1, i2, s, t,dp);
    }
};