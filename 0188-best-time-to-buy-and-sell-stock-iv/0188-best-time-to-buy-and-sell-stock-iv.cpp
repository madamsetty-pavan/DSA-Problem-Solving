// Top Down
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int maxTran = 2;
//      vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2,vector<int>(maxTran,-1e9)));
//    int ans = recurse(prices, prices.size()-1, 0,0, maxTran, dp);
//        return (ans >0 ? ans : 0);
//    }

//    int recurse(vector<int>&prices, int index, int canBuy,int count, int &maxTran, vector<vector<vector<int>>> &dp) {
//        if(count == maxTran){
//            return 0;
//        }
 //       if(index==0){
//            if(canBuy)return -prices[index];
//            return 0;
//       }
//        if(dp[index][canBuy][count]!=-1e9) return dp[index][canBuy][count];
//        int ans = 0;
//        if(canBuy == 1) {
//            ans = -prices[index]+ recurse(prices, index-1, 0,count+1, maxTran,dp);
//            ans = max(ans, recurse(prices, index-1,1,count,maxTran,dp));
//        } else {
//            ans = prices[index] + recurse(prices, index-1, 1, count, maxTran,dp);
//            ans = max(ans, recurse(prices, index-1,0,count,maxTran,dp));
//        }
 //       return dp[index][canBuy][count]=ans;
 //   }
//};

// Bottom up
//class Solution {
//    public:
//         int maxProfit(vector<int>& prices) {
//            int n = prices.size();
//            vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,0)));
//            dp[0][1][0] = dp[0][1][1] = -prices[0];
//            for(int i=1;i<n;i++) {
//                for(int count = 1;count>=0;count--) {
//                    dp[i][0][count] = max(prices[i] + dp[i-1][1][count] , dp[i-1][0][count]);
//                    dp[i][1][count] = max(-prices[i]+ dp[i-1][0][count+1], dp[i-1][1][count]);
//                }
//            }
//            return (dp[n-1][0][0]>0 ? dp[n-1][0][0]:0);
//        }
//};

// Bottom up - Space optmised
class Solution {
    public:
         int maxProfit(int &k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> dp(2, vector<vector<int>>(2,vector<int>(k+1,0)));
            for(int i=0;i<k;i++) {
                dp[0][1][i] = -prices[0];
            }
            for(int i=1;i<n;i++) {
                for(int count = k-1;count>=0;count--) {
                    dp[1][0][count] = max(prices[i] + dp[0][1][count] , dp[0][0][count]);
                    dp[1][1][count] = max(-prices[i]+ dp[0][0][count+1], dp[0][1][count]);
                }
                dp[0] = dp[1];
            }
            return (dp[1][0][0]>0 ? dp[1][0][0]:0);
        }
};