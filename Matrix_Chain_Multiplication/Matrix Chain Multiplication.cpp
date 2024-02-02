#include<bits/stdc++.h>
// Recursion
// int recurse(int* arr, int i, int j) {
//     if(i+1==j) return 0;
//     int ans = 1e9;
//     for(int k = i+1;k<j;k++) {
//         ans = min(ans, recurse(arr, i, k) + recurse(arr,k,j) + (arr[i] *
//             arr[k] * arr[j]));
//     }
//     return ans;
// }
// int matrixChainMultiplication(int* arr, int n) {
//     // Write your code here
//     return recurse(arr, 0, n);
// }

// Top Down Approach
// int recurse(int* arr, int i, int j, vector<vector<int>>&dp) {
//     if(i+1==j) return dp[i][j]=0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int ans = 1e9;
//     for(int k = i+1;k<j;k++) {
//         ans = min(ans, recurse(arr, i, k,dp) + recurse(arr,k,j,dp) + (arr[i] *
//             arr[k] * arr[j]));
//     }
//     return dp[i][j]=ans;
// }
// int matrixChainMultiplication(int* arr, int n) {
//     // Write your code here
//     vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
//     return recurse(arr, 0, n,dp);
// }


// int matrixChainMultiplication(int* arr, int n) {
//     // Write your code here
//     vector<vector<int>>dp(n+1, vector<int>(n+1,0));
//     for(int i=n;i>=0;i--) {
//         for(int j=0;j<=n;j++) {
//             int ans = INT_MAX;
//             for(int k = i+1;k<j;k++) {
//                 ans = min(ans, (dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]));
//             }
//             if(ans!=INT_MAX)dp[i][j] =  ans;
//         }
        
//     }
//     return dp[0][n];
// }

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    vector<vector<int>>dp(n+1, vector<int>(n+1,0));
    for(int i=n;i>=0;i--) {
        for(int j=0;j<=n;j++) {
            int ans = INT_MAX;
            for(int k = i+1;k<j;k++) {
                ans = min(ans, (dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]));
            }
            if(ans!=INT_MAX)dp[i][j] =  ans;
        }
        
    }
    return dp[0][n];
}
