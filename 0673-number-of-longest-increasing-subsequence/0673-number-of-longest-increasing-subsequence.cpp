class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n,{1,1});
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] > nums[j]) {
                    if(dp[i].first < dp[j].first + 1) {
                        dp[i] = {dp[j].first + 1 , dp[j].second};
                    } else if(dp[i].first == dp[j].first +1) {
                        dp[i].second += dp[j].second; 
                    }
                }
            }
            ans = max(ans, dp[i].first);
        }
        int count = 0;
        for(int i=0;i<n;i++) {
            if(dp[i].first == ans) count += dp[i].second;
        }
        return count;
    }
};