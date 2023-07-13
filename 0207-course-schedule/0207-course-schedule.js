/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    let indegree = Array(numCourses).fill(0), graph = new Map();

    for(let i=0;i<numCourses;i++) {
        graph[i] = [];
    }    
    for(let i=0;i<prerequisites.length;i++) {
        graph[prerequisites[i][1]].push(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }    
    for(let i=0;i<numCourses;i++) {
        let j = 0;
        while(j<numCourses) {
            if(indegree[j]==0) {
                break;
            }
            j++;
        }
        if(j==numCourses) return false;
        indegree[j]=-1;
        for(let k = 0;k<graph[j].length;k++) {
            indegree[graph[j][k]]--;
        }
    }
    return true;

};