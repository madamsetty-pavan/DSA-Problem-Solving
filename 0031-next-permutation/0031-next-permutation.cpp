// Approach 1:

// O(n^2)

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         int i = n-1;
//         for(;i>=0;i--) {
//             int minNumber = INT_MAX, minIndex = i;
//             for(int j = i+1;j<n;j++) {
//                 if(nums[j]>nums[i]){
//                     if(minNumber>nums[j]) {
//                         minIndex = j;
//                         minNumber = nums[j];
//                     }
//                 }
//             }
//             if(minIndex != i) {
//                 swap(nums[i],nums[minIndex]);
//                 sort(nums.begin()+i+1,nums.end());
//                 return;
//             }
//         }
//         sort(nums.begin(),nums.end());
//         return;
//     }
// };


// O(n)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        for(;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                break;
            }
        }
        if(i<0) {
            sort(nums.begin(),nums.end());
            return;
        }
        int minNumber = nums[i+1], index = i+1;
        for(int j=i+1;j<nums.size();j++) {
            if(nums[j]>nums[i] && minNumber>nums[j]) {
                index = j;
                minNumber = nums[index];
            }
        }
        swap(nums[i],nums[index]);
        sort(nums.begin()+i+1, nums.end());
    }
};