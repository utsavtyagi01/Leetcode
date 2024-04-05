class Solution {
public:
    void dfs(unordered_map<int,bool>& visited,int src,vector<vector<int>>& isConnected){
        visited[src]=true;
        int size=isConnected[src].size();

        for(int col=0;col<size;col++){
            if(src!=col && isConnected[src][col]==1 &&!visited[col]){
                dfs(visited,col,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int n=isConnected.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited,i,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};
