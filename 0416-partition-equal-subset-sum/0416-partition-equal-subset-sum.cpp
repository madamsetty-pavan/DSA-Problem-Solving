class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums) {
            sum += x;
        }
        if(sum%2!=0) return false;
        sum /=2;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return recurse(nums.size()-1,sum,nums,dp);
    }
    
    bool recurse(int index, int target, vector<int>& nums, vector<vector<int>>&dp) {
        if(target==0) return dp[index][target]=true;
        if(index ==0) {
            return dp[index][target]=(target == nums[index]);
        }
        if(dp[index][target]!=-1) return dp[index][target];
        bool take = false;
        if(target>=nums[index]) {
            take = recurse(index-1,target-nums[index],nums,dp);
        }
        bool notTake = recurse(index-1,target,nums,dp);
        return dp[index][target] = (take || notTake);
    }
};