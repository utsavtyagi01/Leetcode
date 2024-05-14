class Solution {
public:
    int res=0;
    int temp=0;
    void dfs(int row, int col, vector<vector<int> > &grid, vector<vector<int> > &visited){
        visited[row][col]=1;
        temp+=grid[row][col];
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int r=row+drow[i];
            int c=col+dcol[i];
            if(r<0 || r>grid.size()-1 || c<0 || c>grid[0].size()-1)
            continue;
            if(grid[r][c]==0 || visited[r][c]==1)
            continue;
            dfs(r,c,grid,visited);
        }

        visited[row][col]=0;
        res=max(res,temp);
        temp-=grid[row][col];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                continue;
                temp=0;
                dfs(i,j,grid,visited);
            }
        }
        return res;
    }
};
