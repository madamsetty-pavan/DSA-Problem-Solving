class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        recurse(ans,temp,k,n,0, 1);
        return ans;
    }
    void recurse(vector<vector<int>>&ans, vector<int>&temp, int &k, int &target, int sum, int index) {
        if(sum>=target || temp.size()>=k) {
            if(target==sum && temp.size()==k) {
                ans.push_back(temp);
            }
            return;
        }
        for(int i=index;i<=9;i++) {
            temp.push_back(i);
            recurse(ans,temp,k,target,sum+i,i+1);
            temp.pop_back();
        }
    }
};