class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        vector<int> indegree(graph.size(), 0);
        stack<int> s;
        vector<vector<int>> temp(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            for (int j : graph[i]) {
                indegree[i]++;
                temp[j].push_back(i);
            }
        }
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) {
                s.push(i);
            }
        }

        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            result.push_back(curr);
            for (int neighbor : temp[curr]) {
                if (--indegree[neighbor] == 0) {
                    s.push(neighbor);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
