class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int result=INT_MAX;
        queue<pair <pair<int,int> , int> >s;
        vector< vector<int> > visited(grid.size(), vector<int>(grid.size(), 0));
        if(grid[0][0]==1 || grid[grid.size()-1][grid.size()-1]==1)
        return -1;
        s.push({{0,0},1});
        visited[0][0]=1;
        while(!s.empty()){
            int row=s.front().first.first;
            int col=s.front().first.second;
            int total=s.front().second;
            s.pop();
            int drow[]={-1,-1,0,1,1,1,0,-1};
            int dcol[]={0,1,1,1,0,-1,-1,-1,};
            for(int i=0;i<8;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && r< grid.size() && c>=0 && c<grid[0].size() && visited[r][c]==0 && grid[r][c]==0)
               { s.push({{r,c},total+1});
                visited[r][c]=1;}
            }

            if(row==grid.size()-1 && col==grid.size()-1 && total<result)
            result=total;

        }
        if(result!=INT_MAX)
        return result;
        else 
        return -1;


    }
};
