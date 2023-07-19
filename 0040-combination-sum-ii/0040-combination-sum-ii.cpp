class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(candidates, temp, ans, 0, 0, target);
        return ans;
    }
    
    void recurse(vector<int>&candidates, vector<int>&temp, vector<vector<int>>&ans, int index, int sum,int target) {
        if(sum >= target) {
            if(sum == target)ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(candidates[i]>target) break;
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            recurse(candidates,temp,ans,i+1,sum+candidates[i],target);
            temp.pop_back();
        }
    }
};