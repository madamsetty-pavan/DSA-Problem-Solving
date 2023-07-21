class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(candidates,ans,temp, target,0,0);
        return ans;
    }
    
    void recurse(vector<int>&candidates, vector<vector<int>>&ans, vector<int>&temp, int target,int sum,int index) {
        if(sum>=target || index==candidates.size()) {
            if(sum==target) ans.push_back(temp);
            return;
        }
        //not to choose this index
        recurse(candidates,ans,temp,target,sum,index+1);
        temp.push_back(candidates[index]);
        recurse(candidates,ans,temp,target,sum+candidates[index],index);
        temp.pop_back();
    }
};