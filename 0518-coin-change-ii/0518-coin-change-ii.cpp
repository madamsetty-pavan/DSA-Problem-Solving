// Recursive solution
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         return recurse(coins.size()-1,coins, amount);
//     }
    
//     int recurse(int index, vector<int>&coins, int amount) {
//         if(amount==0) return 1;
//         if(index==0) return (amount%coins[0]==0);
//         int notTake = recurse(index-1,coins,amount);
//         int take = 0;
//         if(amount>=coins[index]) {
//             take = recurse(index,coins,amount-coins[index]);
//         }
//         return take + notTake;
//     }
// };

// Recursive solution with memo
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
//         return recurse(coins.size()-1,coins, amount,dp);
//     }
    
//     int recurse(int index, vector<int>&coins, int amount, vector<vector<int>> &dp) {
//         if(amount==0) return dp[index][amount]=1;
//         if(index==0) return dp[index][amount]=(amount%coins[0]==0);   
//         if(dp[index][amount]!=-1) return dp[index][amount];
//         int notTake = recurse(index-1,coins,amount, dp);
//         int take = 0;
//         if(amount>=coins[index]) {
//             take = recurse(index,coins,amount-coins[index],dp);
//         }
//         return dp[index][amount]=take + notTake;
//     }
// };

// Tabulation
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,0));
//         for(int i=0;i<n;i++) {
//             dp[i][0] = 1; 
//         }
//         for(int a=0;a<=amount;a++) {
//             if(a%coins[0]==0) dp[0][a] = 1;
//         }
//         for(int index = 1;index<n;index++) {
//             for(int a = 1; a<=amount; a++) {
//                 int notTake = dp[index-1][a];
//                 int take = 0;
//                 if(a>=coins[index]) {
//                     take = dp[index][a-coins[index]];
//                 }
//                 dp[index][a] = take+notTake;
//             }
//         }
//         return dp[n-1][amount];
//     }
// };

// Tabulation with Space Optimised
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int a=0;a<=amount;a++) {
            if(a%coins[0]==0) prev[a] = 1;
        }
        for(int index = 1;index<n;index++) {
            for(int a = 0; a<=amount; a++) {
                int notTake = prev[a];
                int take = 0;
                if(a>=coins[index]) {
                    take = curr[a-coins[index]];
                }
                curr[a] = take+notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};
