class Solution {
public:
    void func(int i,int j,vector<vector<char> > &grid){
        grid[i][j]='2';
        if(i-1>=0&&grid[i-1][j]=='1')
        func(i-1,j,grid);
        if(i+1<grid.size()&&grid[i+1][j]=='1')
        func(i+1,j,grid);
        if(j-1>=0&&grid[i][j-1]=='1')
        func(i,j-1,grid);
        if(j+1<grid[0].size()&&grid[i][j+1]=='1')
        func(i,j+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
       // vector<vector<int> > visited(grid.size(),vector<int>(grid[0].size(),0));
       int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    func(i,j,grid);
                    count++;
                }
            }
        }
    return count;
    }

};
