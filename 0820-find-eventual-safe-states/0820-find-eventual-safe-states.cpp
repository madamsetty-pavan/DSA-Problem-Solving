class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<bool> isEnd(n,0), visited(n,0);
        for(int i=0;i<n;i++) {
            if(graph[i].size()==0) {
            visited[i] = 1;
            isEnd[i] = 1; 
            }
        }
        for(int i=0;i<n;i++) {
            if(!visited[i])dfs(graph, isEnd, i, visited);
            if(isEnd[i]) ans.push_back(i);
        }
        return ans;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &isEnd, int index, vector<bool> & visited) {
        if(visited[index]) return;
        visited[index] = 1; 
        bool isNodeEnd = true;   
        for(int i=0;i<graph[index].size();i++) {
            if(!visited[graph[index][i]]) {
                dfs(graph, isEnd, graph[index][i], visited);
            } 
            isNodeEnd &= isEnd[graph[index][i]];
        }
        isEnd[index] = isNodeEnd;
    }
};