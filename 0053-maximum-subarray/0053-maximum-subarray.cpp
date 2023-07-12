class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN, n= nums.size();
        for(int i=0;i<n;i++) {
            sum += nums[i];
            if(sum<nums[i]) sum = nums[i];
            ans = max(sum, ans);
        }
        return ans;
    }
};