class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1, n = nums.size();
        while(right<n) {
            if(nums[right] == nums[left]) right++;
            else nums[++left] = nums[right++];
        }
        return left+1;
    }
};