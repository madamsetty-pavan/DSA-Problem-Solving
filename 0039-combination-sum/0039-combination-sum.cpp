class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(ans,temp,candidates,0,0,target);
        return ans;
    }
    
    void recurse(vector<vector<int>>&ans, vector<int>&temp, vector<int>&candidates,int sum, int index, int &target) {
        if(sum>=target || index==candidates.size()) {
            if(sum==target) ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[index]);
        recurse(ans,temp,candidates,sum+candidates[index],index,target);
        temp.pop_back();
        recurse(ans,temp,candidates,sum,index+1,target);
    }
};