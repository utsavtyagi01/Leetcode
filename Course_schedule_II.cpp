class Solution {
public:
         vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result={0};
       if(numCourses==1)
       return result;
       result.pop_back();
        vector<int> edge[numCourses];
        vector<int> indegree(numCourses,0);
        //vector<int> result={};
        for(auto i:prerequisites){
            edge[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
            q.push(i);
        }

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            result.push_back(curr);
            for(int i=0;i<edge[curr].size();i++){
                if(--indegree[edge[curr][i]]==0){
                    q.push(edge[curr][i]);
                }
            }
        }
        if(result.size()==numCourses)
        return result;
        return {};
    }
};
