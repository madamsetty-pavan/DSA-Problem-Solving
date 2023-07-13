class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegrees[prerequisites[i][0]]++;
        }

        for(int i=0;i<numCourses;i++) {
            int j=0;
            while(j<numCourses) {
                if(inDegrees[j]==0) {
                    break;
                }
                j++;
            }
            if(j==numCourses) return false;
            inDegrees[j] = -1;
            for(int k=0;k<graph[j].size();k++) {
                inDegrees[graph[j][k]]--;
            }
        }
        return true;
    }
};