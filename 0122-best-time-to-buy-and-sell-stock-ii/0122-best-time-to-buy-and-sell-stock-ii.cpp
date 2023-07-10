// We have a choice to buy & sell on a given day
// But we can only buy when we do not hold a stock already
// and can only sell when we already having a stock.
// So we have a variable buy which helps in deciding if we can sell/buy
//** So recur on each index with the above sell/buy variable choice and add dp accordingly



// Tabular - most optmised
class Solution {
    public: 
    int maxProfit(vector<int>& prices) {
        vector<int> prev(2,0), curr(2,0);
        for(int index = prices.size()-1;index>=0;index--) {
            for(int buy = 0;buy<=1;buy++) {
                 int profit;
                    if(buy) {
                        profit = max(-prices[index] + prev[0], 0 + prev[1]);
                    }
                    else 
                    {
                        profit = max(prices[index] + prev[1] , 0 + prev[0]);
                    }
                    curr[buy] = profit;
            }
            prev = curr;
        }
        return curr[1];
    } 
};

// Tabular 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        int n = prices.size();
        dp[n][0] = dp[n][1] = 0;
        for(int index = n-1;index>=0;index--) {
            for(int buy =0;buy<=1;buy++) {
                    int profit;
                    if(buy) {
                        profit = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
                    }
                    else 
                    {
                        profit = max(prices[index] + dp[index+1][1] , 0 + dp[index+1][0]);
                    }
                    dp[index][buy] = profit;
                }
        }

        return dp[0][1];
    }
};


// Recursion + MEMO 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return findMax(prices, dp, 0, 1);
    }

    int findMax(vector<int>& prices, vector<vector<int>>& dp, int index,int buy) {
        if(index == prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int profit;
        if(buy) {
            profit = max(-prices[index] + findMax(prices, dp, index+1, 0), 0 + findMax(prices, dp, index+1, 1));
        }
        else 
        {
            profit = max(prices[index] + findMax(prices, dp, index+1, 1) , 0 + findMax(prices, dp, index+1, 0));
        }
        dp[index][buy] = profit;
        return profit;
    }
};
