class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back({});
        recurse(0,nums,ans,temp);
        return ans;
    }
    
    void recurse(int index, vector<int> &nums ,vector<vector<int>>&ans, vector<int> & temp) {
        for(int i=index;i<nums.size();i++) {
            temp.push_back(nums[i]);
            ans.push_back(temp);
            recurse(i+1,nums,ans, temp);
            temp.pop_back();
        }
    }
};