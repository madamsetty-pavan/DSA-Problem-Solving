class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), ansIndex = 0;
        vector<int> dp(n,1), hash(n,-1);
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
                if(nums[i]%nums[prev] == 0) {
                    if(dp[i]< 1+dp[prev]) {
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }
            if(dp[ansIndex] < dp[i]) ansIndex = i;
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