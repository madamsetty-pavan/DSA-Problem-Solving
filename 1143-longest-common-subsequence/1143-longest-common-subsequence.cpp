// Top Down with memo
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
//         return recurse(text1, text2, text1.size()-1, text2.size()-1, dp);
//     }
    
//     int recurse(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp) {
//         if(index1<0 || index2<0) return 0;
//         if(index1==0 && index2==0) {
//             if(text1[index1] == text2[index2]) return dp[index1][index2]=1;
//             return dp[index1][index2]=0;
//         }
//         if(dp[index1][index2] != -1) return dp[index1][index2];
//         if(text1[index1] == text2[index2]) {
//             return dp[index1][index2] = 1 + recurse(text1, text2, index1-1, index2-1,dp);
//         }
//         int ans = 0;
//         ans = max(ans, recurse(text1, text2, index1-1, index2,dp));
//         ans = max(ans, recurse(text1, text2, index1, index2-1,dp));
//         return dp[index1][index2]=ans;
//     }
// };

// Bottom up
class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i = 1;i <= n; i++) {
            for(int j = 1;j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                   dp[i][j] = 1 + dp[i-1][j-1];
                }  else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string str ="";
        int i = n, j = m;
        //cout<<dp[n][m]<<endl;
        while(str.size()<dp[n][m]){
            // cout<<str<<endl;
            if(text1[i-1] == text2[j-1]) {
                str += text1[i-1];
                i--;
                j--;
            } else {
                //cout<<"came"<<endl;
                if(dp[i-1][j]>=dp[i][j-1]) {
                    i--;
                } else j--;
            }
        }
        reverse(str.begin(), str.end());
       cout<<str<<endl;
        return dp[n][m];
    }
};

// Bottom up - Space optimised
// class Solution {
// public:
//     int longestCommonSubsequence(string &text1, string &text2) {
//         int n = text1.size(), m = text2.size();
//         vector<vector<int>> dp(2, vector<int>(m+1,0));
//         for(int i = 1;i <= n; i++) {
//             for(int j = 1;j <= m; j++) {
//                 if(text1[i-1] == text2[j-1]) {
//                    dp[1][j] = 1 + dp[0][j-1];
//                 }  else {
//                     dp[1][j] = max(dp[0][j], dp[1][j-1]);
//                 }
//             }
//             dp[0] = dp[1];
//         }
//         return dp[0][m];
//     }
// };
















