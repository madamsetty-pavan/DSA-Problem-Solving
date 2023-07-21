class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int> temp;
        recurse(candidates,temp,ans,target,0,0);
        return ans;
    }
    
    void recurse(vector<int>& candidates,vector<int> &temp, vector<vector<int>>&ans,int target, int index,int sum) {    
        if(sum>=target) {
            if(sum==target) ans.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++) {
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            recurse(candidates,temp,ans,target,i+1,sum+candidates[i]);
            temp.pop_back();
        }
    }
};