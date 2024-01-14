// Top Down
// class Solution {
// public:
//    int maxProfit(vector<int>& prices) {
//        int ans = recurse(prices, prices.size()-1, 0);
//        return max(ans,0);
//    }
    
  //  int recurse(vector<int>&prices, int index, int canBuy) {
  //      if(index<0) return 0;
 //       if(index == 0) {
 //           if(canBuy) return -prices[0];
 //           return 0;
//        }
//        int ans = 0;
//        if(canBuy == 1) {
//            ans = -prices[index] + recurse(prices,index-2, 0);
//            ans = max(ans, recurse(prices, index-1,1));
 //       } else {
//            ans = prices[index] + recurse(prices, index-1,1);
//            ans = max(ans, recurse(prices, index-1,0));
//        }
//        return ans;
//    }
//};

// Top Down - Dp
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        vector<vector<int>>  dp(n, vector<int>(2,-1e7));
//        int ans = recurse(prices, prices.size()-1, 0, dp);
//        return max(ans,0);
//    }
    
//    int recurse(vector<int>&prices, int index, int canBuy, vector<vector<int>>&dp) {
//        if(index<0) return 0;
//        if(index == 0) {
//            if(canBuy) return -prices[0];
//            return 0;
//        }
//        if(dp[index][canBuy] != -1e7) return dp[index][canBuy];
//        int ans = 0;
//        if(canBuy == 1) {
//            ans = -prices[index] + recurse(prices,index-2, 0,dp);
//            ans = max(ans, recurse(prices, index-1,1,dp));
//        } else {
//            ans = prices[index] + recurse(prices, index-1,1,dp);
//            ans = max(ans, recurse(prices, index-1,0,dp));
//        }
//        return dp[index][canBuy]=ans;
//    }
//};

// class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        if(n<2) return 0;
//        vector<vector<int>>  dp(n, vector<int>(2,0));
//        dp[0][1] = -prices[0];
//        dp[1][1] = max(-prices[1], dp[0][1]);
//        dp[1][0] = max(prices[1] + dp[0][1], dp[0][0]);
//        for(int i = 2;i<n;i++) {
//            dp[i][1] = max(-prices[i] + dp[i-2][0], dp[i-1][1]);
 //           dp[i][0] = max(prices[i] + dp[i-1][1] , dp[i-1][0]);
//        }
//        return max(dp[n-1][0],0);
//    }
//};

// BOTTOM UP - SPACE OPTIMISED
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        vector<vector<int>>  dp(3, vector<int>(2,0));
        dp[0][1] = -prices[0];
        for(int i = 1;i<n;i++) {
            if(i==1) {
                dp[1][1] = max(-prices[i], dp[0][1]); 
                dp[1][0] = max(prices[i] + dp[0][1], dp[0][0]);
                dp[2]=dp[1];
            } else {
                dp[2][1] = max(-prices[i] + dp[0][0], dp[1][1]);
                dp[2][0] = max(prices[i] + dp[1][1], dp[1][0]);
                dp[0] = dp[1];
                dp[1] = dp[2];
            }
        }
        return max(dp[2][0],0);
    }
};