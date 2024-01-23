class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &x:nums) {
            sum += x;
        }
        if(sum % k != 0 || k>sum) return false;
        sum = sum/k;
        for(auto &x:nums) {
            if(x>sum) return false;
        }
        int n = nums.size();
        vector<bool> visited(n,0);
        return recurse(nums, 0, 0, sum, 0, n, k, visited);
    }
    
    bool recurse(vector<int>&nums, int currSet, int currSum, int &requiredSum, int index, int &n, int &k, vector<bool>&visited) {
        if(currSum == requiredSum) {
            if(currSet == k-1) return true;
            return recurse(nums, currSet+1, 0, requiredSum, 0, n, k, visited);
        }
        for(int i=index;i<n;i++) {
            int sum = currSum + nums[i] ;
            if(visited[i] == false && (sum <= requiredSum)) {
                visited[i] = true;
                if(recurse(nums, currSet, sum, requiredSum, i+1, n, k, visited)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
};