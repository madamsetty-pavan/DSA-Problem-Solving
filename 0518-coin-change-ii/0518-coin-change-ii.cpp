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
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return recurse(coins.size()-1,coins, amount,dp);
    }
    
    int recurse(int index, vector<int>&coins, int amount, vector<vector<int>> &dp) {
        if(amount==0) return dp[index][amount]=1;
        if(index==0) return dp[index][amount]=(amount%coins[0]==0);   
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake = recurse(index-1,coins,amount, dp);
        int take = 0;
        if(amount>=coins[index]) {
            take = recurse(index,coins,amount-coins[index],dp);
        }
        return dp[index][amount]=take + notTake;
    }
};

// 