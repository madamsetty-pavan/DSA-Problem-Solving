class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(candidates, ans, temp, target, 0);
        return ans;
    }

    void recurse(vector<int>&candidates, vector<vector<int>>&ans, vector<int>&temp, int target,int index){
        if(target<=0) {
            if(target==0) ans.push_back(temp);
            return;
        }
        for(int i = index;i<candidates.size();i++) {
            if(i!=index && candidates[i]==candidates[i-1] ) continue;
            temp.push_back(candidates[i]);
            recurse(candidates, ans, temp, target - candidates[i], i+1);
            temp.pop_back();
        }
    }
};