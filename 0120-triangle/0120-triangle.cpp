class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(),-1));
       return recurse(triangle, 0, 0, dp);
    }
    
    int recurse(vector<vector<int>>& triangle, int i, int j, vector<vector<int>> &dp) {
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + recurse(triangle,i+1,j, dp);
        int  diagonal =  triangle[i][j] + recurse(triangle,i+1,j+1, dp);
        return dp[i][j] = min(down, diagonal);
    }
};