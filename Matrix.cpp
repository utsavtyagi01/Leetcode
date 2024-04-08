class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int> > q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int> > result(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(mat[i][j]==0){
            q.push({{i,j},0});
            visited[i][j]=1;
            result[i][j]=0;}
            }
        }

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && r<n && c>=0 && c<m && visited[r][c]!=1 ){
                    q.push({{r,c},t+1});
                    visited[r][c]=1;
                    result[r][c]=t+1;
                }
            }

        }
        
        return result;
    }
};
