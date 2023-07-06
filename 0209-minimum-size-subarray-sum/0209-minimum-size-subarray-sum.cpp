class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        int ans = INT_MAX, sum =0;
        while(right<n) {
            sum += nums[right];
            if(sum>=target) {
                ans = min(ans, right-left+1);
            }
            while(sum>=target) {
                sum -= nums[left++];
                if(sum>=target) ans = min(ans, right-left+1);      
            }
            right++;
        }
        while(left<right && sum>=target) {
            sum -= nums[left];
            if(sum>=target) ans = min(ans, right-left+1); 
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};