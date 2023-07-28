// Approach 1: Using take/ not take policy
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> temp;
//         recurse(nums,ans,temp,0);
//         return ans;
//     }
    
//     void recurse(vector<int> &nums,vector<vector<int>>&ans, vector<int>&temp, int index) {
//         if(index==nums.size()) {
//             ans.push_back(temp);
//             return;
//         }
//         temp.push_back(nums[index]);
//         recurse(nums,ans,temp,index+1);
//         temp.pop_back();
//         recurse(nums,ans,temp,index+1);
//     }
// };

// Approach 2: Using choice of numbers for an empty field
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> temp;
            recurse(nums,ans,temp,0);
            return ans;
        }
        
        void recurse(vector<int>&nums,vector<vector<int>>&ans, vector<int>&temp, int index) {
            ans.push_back(temp);
            for(int i=index;i<nums.size();i++) {
                temp.push_back(nums[i]);
                recurse(nums,ans,temp,i+1);
                temp.pop_back();
            }
        }
};