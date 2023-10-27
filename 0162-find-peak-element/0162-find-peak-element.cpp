class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        if(left == right) return left; // only one element
        if(nums[left] > nums[left+1]) return left;
        if(nums[right] > nums[right-1]) return right;
        left++;
        right--;
        while(left<=right) {
            mid = left + (right-left)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] > nums[mid+1]) right = mid - 1 ;
            else left = mid + 1;
        }
        return left;
    }
};