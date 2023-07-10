class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while(left<right) {
            mid = left + (right-left)/2;
            if(nums[right]<nums[mid]) left = mid+1;
            else right = mid; 
        }
        return nums[left];
    }
};

