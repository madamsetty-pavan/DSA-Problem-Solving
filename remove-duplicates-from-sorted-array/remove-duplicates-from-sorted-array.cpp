class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1, n = nums.size();
        while(right<n) {
            while(right<n && nums[right] == nums[left]) right++;
            if(right<n) nums[++left] = nums[right++];
        }
        return left+1;
    }
};