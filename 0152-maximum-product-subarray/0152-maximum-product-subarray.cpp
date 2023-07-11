class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minP = nums[0], maxP = nums[0], ans = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i]<0) {
                swap(minP,maxP);
            }
            minP = min(nums[i], minP*nums[i]);
            maxP = max(nums[i], maxP* nums[i]);
            ans = max(maxP,ans);
        }
        return ans;
    }
};