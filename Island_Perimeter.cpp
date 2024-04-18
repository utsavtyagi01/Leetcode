class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       // queue<pair<int,int> > q;
        int result=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    //q.push({i,j});
                    //break;
                    result+=4;
        
                    if(i-1>=0 && grid[i-1][j]==1)
                    result-=1;
                    if(i+1<grid.size() && grid[i+1][j]==1)
                    result-=1;
                    if(j-1>=0 && grid[i][j-1]==1)
                    result-=1;
                    if(j+1<grid[0].size() && grid[i][j+1]==1)
                    result-=1;
            }}
            //if(!q.empty())
            //break;
        }

        /*while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            result+=4;
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row< grid.size() && col>=0 && col<grid[0].size() && grid[row][col]==1){
                q.push({row,col});
                result-=1;}
            }
        }*/
        return result;

    }
};
