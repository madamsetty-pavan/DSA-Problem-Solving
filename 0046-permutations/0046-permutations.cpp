// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<bool> seen(nums.size(),0);
//         vector<vector<int>> ans;
//         vector<int> temp;
//         recurse(nums,ans,temp,seen);
//         return ans;
//     }
    
//     void recurse(vector<int>&nums,  vector<vector<int>> &ans,  vector<int> &temp, vector<bool> &seen) {
//         if(temp.size()==nums.size()) {
//             ans.push_back(temp);
//             return;
//         }
//         for(int i=0;i<nums.size();i++) {
//             if(seen[i]==0) {
//                 seen[i] = 1;
//                 temp.push_back(nums[i]);
//                 recurse(nums,ans,temp,seen);
//                 temp.pop_back();
//                 seen[i] = 0;
//             }
//         }
//     }
// }
// Approach 1
// Idea: Index based strategy based on seen array 
// Time Complexity : O(n!) * n
// Space complexity: O(n) - Let's optimise further + O(n) - Stack space auxilary

// Approach 2:
// Idea: For each index, run a loop and swap it with other element
// Time Complexity: O(n!*n)
// Space Complexity: O(1) + O(n) - Stack space auxilary
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurse(ans, 0, nums);
        return ans;
    }
    
    void recurse(vector<vector<int>>&ans, int index, vector<int>&nums) {
        if(index==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recurse(ans,index+1,nums);
            swap(nums[index],nums[i]);
        }
    }
};