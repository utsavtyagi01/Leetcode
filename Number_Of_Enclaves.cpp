class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1&&visited[i][0]!=1){
            q.push({i,0});
            visited[i][0]=1;
            grid[i][0]=2;}
            if(grid[i][n-1]==1&&visited[i][n-1]!=1){
                q.push({i,n-1});
                visited[i][n-1]=1;
                grid[i][n-1]=2;
            }
        } 
        for(int i=0;i<n;i++){
            if(grid[0][i]==1&&visited[0][i]!=1){
            q.push({0,i});
            visited[0][i]=1;
            grid[0][i]=2;}
            if(grid[m-1][i]==1&&visited[m-1][i]!=1){
                q.push({m-1,i});
                visited[m-1][i]=1;
                grid[m-1][i]=2;
            }
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && visited[row][col]!=1 && grid[row][col]==1){
                    q.push({row,col});
                    visited[row][col];
                    grid[row][col]=2;
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                count++;
            }
        }
        return count;
    }
};
