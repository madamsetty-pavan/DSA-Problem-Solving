class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> seen(nums.size(),0);
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(nums,ans,temp,seen);
        return ans;
    }
    
    void recurse(vector<int>&nums,  vector<vector<int>> &ans,  vector<int> &temp, vector<bool> &seen) {
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(seen[i]==0) {
                seen[i] = 1;
                temp.push_back(nums[i]);
                recurse(nums,ans,temp,seen);
                temp.pop_back();
                seen[i] = 0;
            }
        }
    }
};