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

// Tp Down DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recurse(nums, n-1, n, dp, n);
    }
    
    int recurse(vector<int>&nums, int index, int prev, vector<vector<int>> &dp, int &n) {
        if(index==0) {
            return dp[index][prev] = (prev == n || nums[index] < nums[prev]);
        }
        if(dp[index][prev] != -1) return dp[index][prev];
        int notTake = recurse(nums, index-1, prev, dp,n);
        int take = 0;
        if(prev == n || nums[index]<nums[prev]) {
            take = 1+recurse(nums, index-1, index, dp,n);
        }
        return dp[index][prev] = max(take, notTake);
    }
};