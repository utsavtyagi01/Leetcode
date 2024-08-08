class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int x=rStart,y=cStart;
        int steps=1;
        int total=rows*cols;
        result.push_back({x,y});
        while(total>result.size()){
            for(int i=0;i<steps;i++){
                y++;
                if((x>=0 && x<rows)&& (y>=0 && y<cols) )
                result.push_back({x,y});
            }
            for(int i=0;i<steps;i++){
                x++;
                if((x>=0 && x<rows)&& (y>=0 && y<cols) )
                result.push_back({x,y});
            }
            steps++;

            for(int i=0;i<steps;i++){
                y--;
                if((x>=0 && x<rows)&& (y>=0 && y<cols) )
                result.push_back({x,y});
            }

            for(int i=0;i<steps;i++){
                x--;
                if((x>=0 && x<rows)&& (y>=0 && y<cols) )
                result.push_back({x,y});
            }
            steps++;
        }

        return result;
    }
};
