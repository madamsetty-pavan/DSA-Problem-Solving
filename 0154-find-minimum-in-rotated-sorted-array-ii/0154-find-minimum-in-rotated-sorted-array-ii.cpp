// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int left = 0, right = nums.size()-1, mid;
//         while(left<right) {
//             mid = left + (right-left)/2;
//             if(nums[mid]==nums[left] && nums[mid]==nums[right]) {
//                 int i = mid+1 , j = mid-1;
//                 while(i<nums.size()&&nums[i]==nums[i-1]) i++;
//                 if(i!=nums.size() && nums[i]<nums[mid]) {
//                     left = mid;
//                     continue;
//                 }
//                 while(j>=0 && nums[j]==nums[j+1]) j--;
//                 if(j>=0 && nums[j]<nums[mid]) {right = mid;continue;}
//             }
//             if(nums[mid]>nums[right]) left = mid+1;
//             else right = mid;
//         }
//         return nums[left];
//     }
// };


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid, ans= INT_MAX;
        while(left<=right) {
            while(left<right && nums[left] == nums[left+1]) left++;
            while(left<right && nums[right] == nums[right-1]) right--;
            mid = left + (right-left)/2;
            if(nums[mid]<=nums[right]) {
                ans = min(nums[mid],ans);
                right = mid -1;
            } else {
                ans = min(ans,nums[left]);
                left = mid +1;
            }
        }
        return ans;
    }
};
