class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0, maxValue = nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--) {
            maxValue = max(maxValue, nums[i]);
            ans = max(ans, maxValue-nums[i]);
        }
        return ans;
    }
};