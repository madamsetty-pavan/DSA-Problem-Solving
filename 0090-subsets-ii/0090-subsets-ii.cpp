class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(nums, temp, ans, 0);
        return ans;
    }
    
    void recurse(vector<int>&nums, vector<int>&temp,  vector<vector<int>>& ans, int index ) {
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++) {
            if(i!=index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            recurse(nums,temp,ans,i+1);
            temp.pop_back();
        }
    }
};