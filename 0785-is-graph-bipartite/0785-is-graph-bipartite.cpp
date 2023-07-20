class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),0);
        for(int i=0;i<graph.size();i++) {
            if(colors[i]==0) {
                if(!checkOkay(graph,i,1,colors)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkOkay(vector<vector<int>>&graph, int index, int color, vector<int>&colors){
        if(colors[index]!=0) return true;
        colors[index] = color;
        for(int i=0;i<graph[index].size();i++) {
            if(colors[graph[index][i]]==color) return false;
            if(colors[graph[index][i]]==0 && !checkOkay(graph,graph[index][i],-color,colors)) return false;
        }
        return true;
    }
};