class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1), hash(n,-1);
        int ansIndex = 0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++) {
                if(nums[i]%nums[prev] == 0) {
                    if(dp[i] < dp[prev]+1) {
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }
            if(dp[ansIndex] < dp[i]) {
                ansIndex = i;
            }
        }
        vector<int> ans;
        while(ansIndex != -1) {
            ans.push_back(nums[ansIndex]);
            ansIndex = hash[ansIndex];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};