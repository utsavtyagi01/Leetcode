class Solution {
public:
    pair<int,int> func(int r1,int c1,vector<vector<int> > &land){
       
        int r2=r1,c2=c1;
        for(;r2<land.size()&&land[r2][c1]==1;r2++);
        for(;c2<land[0].size()&&land[r1][c2]==1;c2++);
          for(int i = r1; i < r2; i++){
            for(int j = c1; j < c2; j++){
                land[i][j] = 2;
            }
        }

        return {r2-1,c2-1};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int> > result;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){
                    auto [r1,c1]=func(i,j,land);
                    result.push_back({i,j,r1,c1});
                }
            }
        }
        return result;
    }
};
