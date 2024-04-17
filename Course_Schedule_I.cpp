class Solution {
public:
    bool dfs(int node, vector<int> edges[], vector<int>& visited, vector<int>& path) {
        visited[node] = 1;
        path[node] = 1;
        for (int neighbor : edges[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, edges, visited, path)) {
                    return true; 
                }
            } else if (path[neighbor]) {
                return true;
            }
        }
        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> edges[numCourses];
        for (const auto& it : prerequisites) {
            edges[it[1]].push_back(it[0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, edges, visited, path)) {
                    return false;
                }
            }
        }
        return true;
    }
};
