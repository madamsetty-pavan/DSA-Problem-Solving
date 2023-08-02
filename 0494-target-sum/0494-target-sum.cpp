class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }

    int recurse(int target, vector<int>&arr, int index, vector<vector<int>>&dp) {
        if(index == 0) {
            if(target==0 && arr[0]==0) return dp[index][target]=2;
            if(target==arr[0] || target ==0) return dp[index][target]=1;
            return dp[index][target]=0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake = recurse(target,arr,index-1,dp);
        int take = 0;
        if(arr[index]<=target) {
            take = recurse(target-arr[index],arr,index-1,dp);
        }
        return dp[index][target] = (take + notTake);
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        // Write your code here.
        int total = 0;
        for(auto &x:arr) {
            total += x;
        }
        if((total-d)%2!=0 || (total-d)<0) return 0;
        int sum = (total-d)/2;
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        return recurse(sum, arr, arr.size()-1,dp);
    }
};