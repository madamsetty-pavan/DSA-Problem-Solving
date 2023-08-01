class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums, temp;
        for(int i=1;i<=n;i++) {
            nums.push_back(i);
        }
        recurse(nums,temp,0,ans,k);
        return ans;
    }
    
    void recurse(vector<int>&nums, vector<int>&temp, int index, vector<vector<int>>&ans, int &k) {
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        for(int i = index;i<nums.size();i++) {
            temp.push_back(nums[i]);
            recurse(nums,temp,i+1,ans,k);
            temp.pop_back();
        }
    }
};