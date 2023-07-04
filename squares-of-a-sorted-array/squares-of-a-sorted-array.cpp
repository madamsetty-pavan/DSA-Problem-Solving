class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int left = 0, right = nums.size()-1;
        for (int i = nums.size()-1; i>=0; i--) {
            if(abs(nums[left])>abs(nums[right])) {
                ans[i] = nums[left] * nums[left];
                left++;
            } else {
                ans[i] = nums[right] * nums[right];
                right --;
            }
        }
        return ans;
    }
};