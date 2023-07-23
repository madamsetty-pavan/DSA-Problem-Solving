class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long sum = 0, ans = 0;
        for(int i=nums.size()-1;i>=0;i--) {
            if(sum>=nums[i]) {
                sum += nums[i];
            } else sum = nums[i];
            ans = max(sum,ans);
        }
        return ans;
    }
};