class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        //Construct the graph
        for(int i=0;i<prerequisites.size();i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }

        queue<int> qu;
        for(int i=0;i<numCourses;i++) {
            if(indegrees[i] == 0) qu.push(i);
        }
        vector<int> courseStructure;
        int n, front;
        while(!qu.empty()) {
            n = qu.size();
            for(int i=0;i<n;i++) {
                front = qu.front();
                qu.pop();
                courseStructure.push_back(front);
                for(int i=0;i<graph[front].size();i++) {
                    indegrees[graph[front][i]]--;
                    if(indegrees[graph[front][i]]==0) {
                        qu.push(graph[front][i]);
                    }
                }
            }
        }
        if(courseStructure.size()==numCourses) return courseStructure;
        return {};
    }
};