class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(ans, temp, nums ,0, target, 0);
        return ans;
    }
    
    void recurse(vector<vector<int>> &ans, vector<int>&temp, vector<int>&nums,int sum, int target, int index) {
        if(sum>=target || index==nums.size()) 
        {
            if(sum==target) ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        recurse(ans,temp,nums,sum+nums[index],target,index);
        temp.pop_back();
        recurse(ans,temp,nums,sum,target,index+1);
    }
};