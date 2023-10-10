class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while (left<=right) {
            while(left<right && nums[left]  == nums[left+1]) left++;
            while(left<right && nums[right] == nums[right-1]) right--;
            mid = left + (right-left)/2;
            if(nums[mid] == target) return true;
            if(nums[mid]<=nums[right]) {
                // mid - right is sorted
                if(target> nums[mid] && target<=nums[right]) {
                    left = mid + 1;
                } else right = mid -1;
            }
            else{
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else left = mid+1;
            }
        }
        return false;
    }
};