// Recursion - Time Limit Exceeded
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         return recurse(nums, nums.size()-1, INT_MAX);
//     }
    
//     int recurse(vector<int>&nums, int index, int prev) {
//         if(index==0) {
//             return (nums[index] < prev);
//         }
//         int notTake = recurse(nums, index-1, prev);
//         int take = 0;
//         if(nums[index]<prev) {
//             take = 1+recurse(nums, index-1, nums[index]);
//         }
//         return max(take, notTake);
//     }
// };

// Top Down DP
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return recurse(nums, n-1, n, dp, n);
//     }
    
//     int recurse(vector<int>&nums, int index, int prev, vector<vector<int>> &dp, int &n) {
//         if(index==0) {
//             return dp[index][prev] = (prev == n || nums[index] < nums[prev]);
//         }
//         if(dp[index][prev] != -1) return dp[index][prev];
//         int notTake = recurse(nums, index-1, prev, dp,n);
//         int take = 0;
//         if(prev == n || nums[index]<nums[prev]) {
//             take = 1+recurse(nums, index-1, index, dp,n);
//         }
//         return dp[index][prev] = max(take, notTake);
//     }
// };

//Bottom up DP
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,0));
//         for(int i = 0;i<n;i++) {
//             for(int prev=n;prev>=0;prev--) {
//                 if(i==0) {
//                     if(prev == n || nums[i]<nums[prev]) dp[i][prev] = 1;
//                 } else {
//                     dp[i][prev] = dp[i-1][prev];
//                     if(prev == n || nums[i]<nums[prev]) dp[i][prev] = max(dp[i][prev], 1 + dp[i-1][i]);
//                 }
//             }
//         }
//         for(int i=0;i<n;i++) {
//             for(int prev = 0;prev<=n;prev++) {
//                 cout<<dp[i][prev]<<" ";
//             }
//             cout<<endl;
//         }
        
//         return dp[n-1][n];
//     }
// };


// Bottom up DP - Space optmised
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(2,vector<int>(n+1,0));
//         for(int i = 0;i<n;i++) {
//             for(int prev=n;prev>=0;prev--) {
//                 if(i==0) {
//                     if(prev == n || nums[i]<nums[prev]) dp[1][prev] = 1;
//                 } else {
//                     dp[1][prev] = dp[0][prev];
//                     if(prev == n || nums[i]<nums[prev]) dp[1][prev] = max(dp[1][prev], 1 + dp[0][i]);
//                 }
//             }
//             dp[0] = dp[1];
//         }
//         return dp[1][n];
//     }
// };


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int prev = 0;prev<i;prev++) {
                if(nums[i]>nums[prev]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            ans  = max(ans, dp[i]);
        }
        return ans;
    }
};
