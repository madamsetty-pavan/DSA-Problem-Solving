class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid, n = nums.size();
        while(left<right) {
            mid = left + (right-left)/2;
            if(nums[mid]==nums[left] && nums[right] ==nums[mid]) {
                int i = mid +1, j = mid-1;
                while(i<n && nums[i]==nums[i-1]) i++;
                if(i<n && nums[i]<nums[mid]) { left = mid; continue;}
                while(j>0 && nums[j]==nums[j+1]) j--;
                if(j>0 && nums[j]<nums[mid]) {right = mid;  continue;}
            }
            if(nums[mid]>nums[right]) left = mid+1;
            else right = mid; 
        }
        return nums[left];
    }
};