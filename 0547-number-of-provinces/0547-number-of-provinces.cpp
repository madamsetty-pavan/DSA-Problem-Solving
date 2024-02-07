class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int provinces = 0;
        for(int i=0;i<n;i++) {
            if(visited[i] == false) {
                provinces++;
                recurse(isConnected, visited, i);
            }
        }
        return provinces;
    }
    
    void recurse(vector<vector<int>>& isConnected, vector<int>&visited, int index) {
        if(visited[index]) return;
        visited[index] = 1;
        for(int i=0;i<isConnected[index].size();i++) {
            if(isConnected[index][i] == 1) {
                recurse(isConnected, visited,i);   
            }
        }
    }
};