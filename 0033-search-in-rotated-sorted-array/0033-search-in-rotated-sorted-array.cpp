class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while(left<right) {
            mid = left +(right-left)/2;
            if(nums[mid]>nums[right]) left =mid+1;
            else right = mid;
        }
        if(target<=nums[nums.size()-1]) right = nums.size()-1;
        else left = 0;
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        if(nums[left]==target) return left;
        return -1; 
    }
};