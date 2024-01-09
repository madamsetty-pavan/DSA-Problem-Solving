// Top Down
// int recurse(string &str1,string &str2,int index1, int index2){
//     if(index1<0 || index2<0) return 0;
//     int ans = 0;
//     while(index1>=0 && index2>=0 && str1[index1]==str2[index2]) {
//         ans++;
//         index1--;
//         index2--;
//     }
//     ans = max(ans, recurse(str1, str2, index1-1, index2));
//     ans = max(ans, recurse(str1, str2, index1, index2-1));
//     return ans;
// }


// int lcs(string &str1, string &str2){
//     // Write your code here.
//     return recurse(str1, str2, str1.size()-1, str2.size()-1);
// }


// Top Down - DP Optimised
// int recurse(string str1,string str2,int index1, int index2,
// vector<vector<int>> &dp){
//     if(index1<=0 || index2<=0) return 0;
//     if(dp[index1][index2] != -1) return dp[index1][index2];
//     int ans = 0;
//     int i1 = index1, i2 = index2;
//     while(i1>0 && i2>0 && str1[i1-1]==str2[i2-1]) {
//         ans++;
//         i1--;
//         i2--;
//     }
//     ans = max(ans, recurse(str1, str2, index1-1, index2, dp));
//     ans = max(ans, recurse(str1, str2, index1, index2-1, dp));
//     return dp[index1][index2] = ans;
// }


// int lcs(string &str1, string &str2){
//     // Write your code here.
//     vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1,-1));
//     return recurse(str1, str2, str1.size(), str2.size(), dp);
// }




// Bottom up
// int lcs(string &str1, string &str2){
//     int n = str1.size(), m = str2.size();
//     vector<vector<int>> dp(n+1, vector<int>(m+1,0));
//     int ans = 0;
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=m;j++) {
//             if(str1[i-1] == str2[j-1]) {
//                 dp[i][j] = 1 + dp[i-1][j-1];
//                 ans = max(ans, dp[i][j]);
//             } else {
//                 dp[i][j] = 0;
//             }
//         }
//         dp[0] = dp[1];
//     }
//     return ans;
// }

// Bottom up - optimised
int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(2, vector<int>(m+1,0));
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[1][j] = 1 + dp[0][j-1];
                ans = max(ans, dp[1][j]);
            } else {
                dp[1][j] = 0;
            }
        }
        dp[0] = dp[1];
    }
    return ans;
}

















