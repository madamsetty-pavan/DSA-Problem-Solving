// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int left = 0, right = nums.size()-1, mid;
//         while(left<right) {
//             mid = left + (right-left)/2;
//             if(nums[mid]>nums[right]) left = mid+1;
//             else right = mid;
//         }
//         return nums[left];
//     }
// };



class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX, left = 0, right = nums.size()-1, mid;
        while(left<=right) {
            mid = left + (right-left)/2;
            // left is sorted
            if(nums[left]<=nums[mid]) {
                ans = min(ans, nums[left]);
                // remove the left part
                left = mid +1;
            } else {
                ans = min(ans,nums[mid]);
                // remove the right part
                right = mid -1;
            }
        }
        return ans;
    }
};