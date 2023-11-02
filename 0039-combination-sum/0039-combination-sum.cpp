class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(0, candidates, temp, ans, target);
        return ans;
    }

    void recurse(int index, vector<int>&candidates, vector<int>&temp, vector<vector<int>>&ans, int target) {
        if(index>=candidates.size() || target<=0 || candidates[index]>target) {
            if(target==0) ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[index]);
        recurse(index, candidates, temp, ans, target-candidates[index]);
        temp.pop_back();
        recurse(index+1, candidates, temp, ans, target);
    }

};