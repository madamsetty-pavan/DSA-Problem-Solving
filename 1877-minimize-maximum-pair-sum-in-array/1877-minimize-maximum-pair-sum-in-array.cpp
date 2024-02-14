class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size()-1, ans =INT_MIN;
        while(left<right) {
            ans = max(ans, nums[right--]+nums[left++]);
        }
        return ans;
    }
};