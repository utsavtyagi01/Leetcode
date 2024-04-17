class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),0);
        // Green = 1, Red = 2
        queue<int> q;
        for(int node=0;node<graph.size();node++){
        if(color[node]==0){
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int curr=q.front();
            int currcolor=color[curr];
            int colour;
            if(currcolor==1)
            colour=2;
            else
            colour=1;
            q.pop();
            for(int i=0;i<graph[curr].size();i++){
                if(color[graph[curr][i]]==0){
                    color[graph[curr][i]]=colour;
                    q.push(graph[curr][i]);
                }
                else{
                    if(color[graph[curr][i]]==currcolor)
                    return false;

                }
            }
        }
        }
        }
        return true;
    }
};
