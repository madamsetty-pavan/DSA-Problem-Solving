class Solution {
    public:
         int maxProfit(vector<int>& prices, int &fees) {
            int n = prices.size();
            vector<vector<int>> dp(2, vector<int>(2,0));
            dp[0][1] = -prices[0]- fees;
            for(int i=1;i<n;i++) {
                dp[1][0] = max(prices[i] + dp[0][1] , dp[0][0]);
                dp[1][1] = max(-prices[i]+ dp[0][0] - fees, dp[0][1]);
                dp[0] = dp[1];
            }
            return (dp[0][0]>0 ? dp[0][0]:0);
        }
};