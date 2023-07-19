class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        vector<int>temp;
        recurse(nums, ans, temp ,index);
        return ans;
    }
    
    void recurse(vector<int> &nums, vector<vector<int>>& ans, vector<int>&temp ,int index) {
        if(index>=nums.size()) {ans.push_back(temp); return;}
        temp.push_back(nums[index]);
        recurse(nums,ans,temp,index+1);
        temp.pop_back();
        recurse(nums,ans,temp,index+1);
    }
};