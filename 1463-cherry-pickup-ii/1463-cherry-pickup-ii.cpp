// Recursive

// class Solution {
// public:
    
    long long recurse(vector<vector<int>>& grid, int i, int j1, int j2)  {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1) {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        long long ans = 0;
        for(int l1=-1;l1<2;l1++)  {
            for(int l2=-1;l2<2;l2++) {
                if(j1 == j2) ans = max(ans, grid[i][j1]+recurse(grid,i+1,j1+l1,j2+l2));
                else ans = max(ans, grid[i][j1]+grid[i][j2]+recurse(grid,i+1,j1+l1,j2+l2));
            }
        }
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        return recurse(grid,0,0,grid[0].size()-1);
    }
};

// Recurse + Memo
class Solution {
public:
    
    long long recurse(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<long long>>> &dp)  {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1) {
            if(j1==j2) return dp[i][j1][j2]=grid[i][j1];
            else return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        long long ans = 0;
        for(int l1=-1;l1<2;l1++)  {
            for(int l2=-1;l2<2;l2++) {
                if(j1 == j2) ans = max(ans, grid[i][j1]+recurse(grid,i+1,j1+l1,j2+l2,dp));
                else ans = max(ans, grid[i][j1]+grid[i][j2]+recurse(grid,i+1,j1+l1,j2+l2,dp));
            }
        }
        return dp[i][j1][j2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<long long>>> dp(grid.size(),vector<vector<long long>>(grid[0].size(),vector<long long>(grid[0].size(),-1)));
        return recurse(grid,0,0,grid[0].size()-1,dp);
    }
};


#include <bits/stdc++.h> 

// // Bottom up
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c,vector<int>(c,0)));

    for(int j=0;j<c;j++) {
        for(int j1=c-1;j1>=0;j1--) {
            if(j==j1) dp[r-1][j][j1] = grid[r-1][j];
            else dp[r-1][j][j1] = grid[r-1][j]+grid[r-1][j1];
        }
    }

    for(int i=r-2;i>=0;i--) {
        for(int a=0;a<c;a++) {
            for(int b=c-1;b>=0;b--) {
                if(a==b) {
                    dp[i][a][b] = grid[i][a];
                } else 
                    dp[i][a][b] = grid[i][a] + grid[i][b];
                int temp1 = 0;
                for(int i1 = -1;i1<2;i1++) {
                    for(int j1=-1;j1<2;j1++) {
                        if(a+i1>=0 && a+i1<c && b+j1>=0 && b+j1<c) {
                             temp1 = max(temp1, dp[i+1][a+i1][b+j1]);
                        }
                    }
                }
                dp[i][a][b] +=temp1;
            }
        }
    }

    return dp[0][0][c-1];
}


// Bottom-up - Space Optimised
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(c,vector<int>(c,0)));

    for(int j=0;j<c;j++) {
        for(int j1=c-1;j1>=0;j1--) {
            if(j==j1) dp[1][j][j1] = grid[r-1][j];
            else dp[1][j][j1] = grid[r-1][j]+grid[r-1][j1];
        }
    }

    for(int i=r-2;i>=0;i--) {
        for(int a=0;a<c;a++) {
            for(int b=c-1;b>=0;b--) {
                if(a==b) {
                    dp[0][a][b] = grid[i][a];
                } else 
                    dp[0][a][b] = grid[i][a] + grid[i][b];
                int temp1 = 0;
                for(int i1 = -1;i1<2;i1++) {
                    for(int j1=-1;j1<2;j1++) {
                        if(a+i1>=0 && a+i1<c && b+j1>=0 && b+j1<c) {
                             temp1 = max(temp1, dp[1][a+i1][b+j1]);
                        }
                    }
                }
                dp[0][a][b] +=temp1;
            }
        }
        dp[1] = dp[0];
    }

    return dp[0][0][c-1];
}

