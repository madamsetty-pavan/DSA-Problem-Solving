class Solution {
public:
    int recurse(int i, int j, int m, int n,  vector<vector<int>> &dp) {
        if(i==m && j==n) { return dp[i][j] = 1;}
        if(i>m || j>n || i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = recurse(i+1,j,m,n,dp);
        ans += recurse(i,j+1,m,n,dp);
        return dp[i][j] = ans;
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recurse(0,0,m-1,n-1,dp);
    }
};