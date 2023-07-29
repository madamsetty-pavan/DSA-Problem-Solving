// // Recursion
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(auto x:nums) {
//             sum += x;
//         }
//         if(sum%2!=0) return false;
//         sum /=2;
//         return recurse(nums.size()-1,sum,nums);
//     }
    
//     bool recurse(int index, int target, vector<int>& nums) {
//         if(target==0) return true;
//         if(index ==0) {
//             return (target == nums[index]);
//         }
//         bool take = false;
//         if(target>=nums[index]) {
//             take = recurse(index-1,target-nums[index],nums);
//         }
//         bool notTake = recurse(index-1,target,nums);
//         return take || notTake;
//     }
// };


// // Recursion with memo
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(auto x:nums) {
//             sum += x;
//         }
//         if(sum%2!=0) return false;
//         sum /=2;
//         vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
//         return recurse(nums.size()-1,sum,nums,dp);
//     }
    
//     bool recurse(int index, int target, vector<int>& nums, vector<vector<int>>&dp) {
//         if(target==0) return dp[index][target]=true;
//         if(index ==0) {
//             return dp[index][target]=(target == nums[index]);
//         }
//         if(dp[index][target]!=-1) return dp[index][target];
//         bool take = false;
//         if(target>=nums[index]) {
//             take = recurse(index-1,target-nums[index],nums,dp);
//         }
//         bool notTake = recurse(index-1,target,nums,dp);
//         return dp[index][target] = (take || notTake);
//     }
// };



// Tabulation
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(auto x:nums) {
//             sum += x;
//         }
//         if(sum%2!=0) return false;
//         sum /=2;
//         vector<vector<int>> dp(nums.size(),vector<int>(sum+1,0));
//         for(int i=0; i<nums.size();i++) {
//             dp[i][0] = 1;
//         }
//         if(nums[0]<=sum) dp[0][nums[0]] = 1;
//         for(int index = 1;index<nums.size();index++) {
//             for(int target = 0;target<=sum;target++) {
//                 bool take = false;
//                 if(target>=nums[index]) {
//                     take = dp[index-1][target-nums[index]];
//                 }
//                 bool notTake = dp[index-1][target];
//                 dp[index][target] = take || notTake;
//             }
//         }
//         return dp[nums.size()-1][sum];
//     }
// };

// Tabulation - Space Optimised

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums) {
            sum += x;
        }
        if(sum%2!=0) return false;
        sum /=2;
        vector<int> prev(sum+1,0), temp(sum+1,0);
        prev[0] = 1;
        if(nums[0]<=sum) temp[nums[0]] = 1;
        for(int index = 1;index<nums.size();index++) {
            for(int target = 0;target<=sum;target++) {
                bool take = false;
                if(target>=nums[index]) {
                    take = prev[target-nums[index]];
                }
                bool notTake = prev[target];
                temp[target] = take || notTake;
            }
            prev = temp;
        }
        return prev[sum];
    }
};



