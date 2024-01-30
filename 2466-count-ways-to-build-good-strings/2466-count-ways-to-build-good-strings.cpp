// class Solution {
// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         string zString = "";
//         string oString = "";
//         for(int i=0;i<zero;i++) {
//             zString += '0';
//         }
//         for(int i=0;i<one;i++) {
//             oString += '1';
//         }
//         vector<int> dp(high+1,-1);
//         return (recurse("", low, high, zString, oString, dp));
//     }
//     int recurse(string str, int &low, int &high, string &zString ,string &oString, vector<int>&dp) {
//         int n = str.size();
//         if(n>high) return 0;
//         int ans = 0;
//         if(dp[n]!=-1) return dp[n];
//         if(n>=low && n<=high) ans += 1;
//         ans += recurse(str + zString, low, high, zString, oString,dp);
//         ans += recurse(str + oString, low, high, zString, oString,dp);
//         return dp[n]=ans% 1000000007;
//     }
// };


class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return (recurse(0, low, high, zero, one, dp));
    }
    int recurse(int n, int &low, int &high,int &zero, int &one, vector<int>&dp) {
        if(n>high) return 0;
        int ans = 0;
        if(dp[n]!=-1) return dp[n];
        if(n>=low && n<=high) ans += 1;
        ans += recurse(n+zero, low, high, zero, one,dp);
        ans += recurse(n+one, low, high, zero, one,dp);
        return dp[n]=ans% 1000000007;
    }
};