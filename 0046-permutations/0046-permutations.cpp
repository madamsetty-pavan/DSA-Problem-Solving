// Approach 1: We maitain a map and maitain a loop from 0 to n and
// check if the num is already taken.
// If not taken we will mark as taken, add it to our buffer array and recur further
// Base condition: if the buffer array size is equal to nums size we will add it to the answer

// TC: O(n! * n) , SC: O(n) + O(n) [Auxilary space]

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> buffer;
//         vector<bool> freq(nums.size(),0);
//         recurse(nums, buffer, ans, freq);
//         return ans;
//     }
    
//     void recurse(vector<int>&nums, vector<int>&buffer, vector<vector<int>>&ans, vector<bool>&freq) {
//         if(nums.size()==buffer.size()) {
//             ans.push_back(buffer);
//             return;
//         }
//         for(int i=0;i<nums.size();i++) {
//             if(!freq[i]) {
//                 freq[i] = 1;
//                 buffer.push_back(nums[i]);
//                 recurse(nums,buffer,ans,freq);
//                 buffer.pop_back();
//                 freq[i]=0;
//             }
//         }
//     }
// };


// Approach 2: 
// We start from index and keep swaping all the elements till the end of index in the array


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurse(nums, ans, 0);
        return ans;
    }
    
    void recurse(vector<int>&nums, vector<vector<int>>&ans, int index) {
        if(index==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++) {
            swap(nums[index],nums[i]);
            recurse(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
};











