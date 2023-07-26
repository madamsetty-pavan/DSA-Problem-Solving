class Solution {
public:
    int recurse(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if(i==0 && j==0) return dp[i][j]=grid[0][0];
        if(dp[i][j]!= -1) return dp[i][j];
        int ans = INT_MAX;
        if(i-1>=0)
         ans = grid[i][j]+ recurse(grid, i-1, j,dp);
        if(j-1>=0)
            ans = min(ans, grid[i][j]+ recurse(grid,i,j-1,dp));
        return dp[i][j]=ans;
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        recurse(grid,m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};