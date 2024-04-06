class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n =grid[0].size();
        int visited[m][n];
        queue<pair<pair<int,int>,int> >q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=2;
                }
                else
                visited[i][j]=0;
            }
        }
        int time=0;
        pair<pair<int,int>,int> front;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r + drow[i];
                int col=c+ dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && visited[row][col]!=2 && grid[row][col]==1){
                q.push({{row,col},t+1});
                visited[row][col]=2;
                }
            }
            if(t>time)
            time=t;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]!=2&&grid[i][j]==1)
                return -1;
            }
        } 
        return time;

    }
};
