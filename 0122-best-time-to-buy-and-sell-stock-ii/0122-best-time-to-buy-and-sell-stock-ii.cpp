// Recursion
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int ans = recurse(prices, prices.size()-1, 0);
//         return (ans>0 ? ans:0);
//     }
//     int recurse(vector<int>&prices, int index, bool canBuy) {
//         if(index == 0) {
//             if(canBuy) return -prices[index];
//             return 0;
//         }
//         int ans = 0;
//         if(canBuy == 1) {
//             // Buy and recurse further
//             ans = -prices[index] + recurse(prices, index-1, 0);
//             // NO Buy and recurse further
//             ans = max(ans, recurse(prices, index-1, 1));
//         } else {
//             // Sell first and buy later
//             ans =  prices[index] + recurse(prices, index-1, 1);
//             // No sell
//             ans = max(ans, recurse(prices, index-1, 0));
//         }
//         return ans;
//     }
// };


// Recursion - Dp - BUT we will get memory limit exceeded problem
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1e9));
        int ans = recurse(prices, prices.size()-1, 0, dp);
        return (ans>0 ? ans:0);
    }
    int recurse(vector<int>&prices, int index, bool canBuy, vector<vector<int>> &dp) {
        if(index == 0) {
            if(canBuy) return -prices[index];
            return 0;
        }
        if(dp[index][canBuy] != -1e9) return dp[index][canBuy];
        int ans = 0;
        if(canBuy == 1) {
            // Buy and recurse further
            ans = -prices[index] + recurse(prices, index-1, 0, dp);
            // NO Buy and recurse further
            ans = max(ans, recurse(prices, index-1, 1, dp));
        } else {
            // Sell first and buy later
            ans =  prices[index] + recurse(prices, index-1, 1, dp);
            // No sell
            ans = max(ans, recurse(prices, index-1, 0, dp));
        }
        return dp[index][canBuy]=ans;
    }
};

// Bottom up
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> dp(prices.size(), vector<int>(2,0));
//         int ans = recurse(prices, prices.size()-1, 0, dp);
//         return (ans>0 ? ans:0);
//     }
//     int recurse(vector<int>&prices, int index, bool canBuy, vector<vector<int>> &dp) {
//         if(index == 0) {
//             if(canBuy) return -prices[index];
//             return 0;
//         }
//         if(dp[index][canBuy] != -1e7) return dp[index][canBuy];
//         int ans = 0;
//         if(canBuy == 1) {
//             // Buy and recurse further
//             ans = -prices[index] + recurse(prices, index-1, 0, dp);
//             // NO Buy and recurse further
//             ans = max(ans, recurse(prices, index-1, 1, dp));
//         } else {
//             // Sell first and buy later
//             ans =  prices[index] + recurse(prices, index-1, 1, dp);
//             // No sell
//             ans = max(ans, recurse(prices, index-1, 0, dp));
//         }
//         return dp[index][canBuy]=ans;
//     }
// };