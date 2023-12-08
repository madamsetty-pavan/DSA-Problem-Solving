class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return recurse(0,0,m,n,dungeon, dp);
    }
    
    int recurse(int i, int j, int &m, int &n, vector<vector<int>>& dungeon,  vector<vector<int>> &dp) {
        if(i>=m || j>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]<=0) return dp[i][j]=1-dungeon[i][j];
            return dp[i][j]=1;
        } 
        if(i+1 < m) {
            ans = min(ans, recurse(i+1,j,m,n,dungeon, dp));
        }
        if(j+1<n) {
            ans = min(ans, recurse(i,j+1,m,n,dungeon, dp));
        }
        ans = ans - dungeon[i][j];
        if(ans<=0) return dp[i][j]=1;
        return dp[i][j]=ans;
    }
};