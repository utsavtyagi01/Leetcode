class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        stack<pair<int,int> > s;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0 || i==m-1 || j==n-1)&&board[i][j]=='O'){
                s.push({i,j});
                visited[i][j]=1;
                board[i][j]='S';
                }
            }
        }

        while(!s.empty()){
            int r=s.top().first;
            int c=s.top().second;
            s.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && visited[row][col]!=1 && board[row][col]=='O'){
                    board[row][col]='S';
                    visited[row][col]=1;
                    s.push({row,col});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                board[i][j]='X';
                }
                else if(board[i][j]=='S')
                board[i][j]='O';
            }
        }
    }
};
