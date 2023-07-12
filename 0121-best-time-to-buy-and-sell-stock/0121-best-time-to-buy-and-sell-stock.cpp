class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0, minValue = nums[0];
        for(int i=0;i<nums.size();i++) {
            minValue = min(minValue, nums[i]);
            ans = max(ans, nums[i]-minValue);
        }
        return ans;
    }
};