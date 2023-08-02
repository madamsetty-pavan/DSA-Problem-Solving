class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int ans = recurse(coins.size()-1, coins ,amount,dp);
        if(ans>=1e8) return -1;
        return ans;
    }

    int recurse(int index, vector<int>&coins, int amount, vector<vector<int>> &dp) {
        if(index<0 || amount<0) return 1e8;
        if(amount==0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake = recurse(index-1, coins, amount,dp);
        int take = 1e8;
        if(amount>=coins[index]) {
            take = 1+recurse(index, coins, amount-coins[index],dp);
        }
        return dp[index][amount]=min(notTake, take); 
    }
};