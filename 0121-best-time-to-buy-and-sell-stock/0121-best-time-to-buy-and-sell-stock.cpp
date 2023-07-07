class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 ,maxNum = 0;
        for(int i = prices.size()-1;i>=0;i--) {
            maxNum = max(maxNum, prices[i]);
            ans = max(maxNum - prices[i], ans);
        }
        return ans;
    }
};