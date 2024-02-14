class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0, n = nums.size()-1, ans = INT_MIN;
        while(left<n-left) {
            ans = max(ans, nums[n-left]+nums[left++]);
        }
        return ans;
    }
};