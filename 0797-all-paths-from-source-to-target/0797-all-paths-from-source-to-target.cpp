class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = graph.size();
        temp.push_back(0);
        recurse(ans,temp, graph, 0, n);
        return ans;
    }
    
    void recurse(vector<vector<int>>&ans, vector<int>&temp, vector<vector<int>>&graph, int index, int &n) {
        if(index >= n-1) {
            if(index == n-1) ans.push_back(temp);
            return;
        }
        for(int i =0;i<graph[index].size();i++) {
            temp.push_back(graph[index][i]);
            recurse(ans,temp,graph,graph[index][i],n);
            temp.pop_back();
        }
    }
};