class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, n= nums.size();
        while(right<n) {
            if(nums[right]!=0){
                nums[left++] = nums[right];
            }
            right++;
        }
        while(left<n) {
            nums[left++] = 0;
        }
    }
};