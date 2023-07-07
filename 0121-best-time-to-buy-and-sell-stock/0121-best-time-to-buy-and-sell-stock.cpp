class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 ,minNum = INT_MAX;

        // Max logic
        // for(int i = prices.size()-1;i>=0;i--) {
        //     maxNum = max(maxNum, prices[i]);
        //     ans = max(maxNum - prices[i], ans);
        // }

        // Min logic
        for(int i=0;i<prices.size(); i++) {
            minNum = min(minNum, prices[i]);
            ans = max(prices[i]-minNum, ans);
        }
        return ans;
    }
};