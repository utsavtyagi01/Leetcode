class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0)); // Initialize visited array
       
        queue< pair<int,int> > q;

        q.push({sr,sc});
        visited[sr][sc]=1;
        //if(image[sr][sc]!=0)
        int oc=image[sr][sc];
        image[sr][sc]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && visited[row][col]!=1 && image[row][col]==oc){
                    image[row][col]=color;
                    visited[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        return image;
    }
};
