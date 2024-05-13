class Solution {
public:
    int binaryToDecimal(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
    int base = 1; 
  
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
        dec_value += last_digit * base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==0)
                    grid[i][j]=1;
                    else
                    grid[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<grid[0].size();i++){
            int cz=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==0)
                cz++;
            }
            if(cz > grid.size()/2){
              for(int j=0;j<grid.size();j++){
                if(grid[j][i]==0)
                grid[j][i]=1;
                else
                grid[j][i]=0;
            }
            }
            
        }
        int result=0;
        for(int i=0;i<grid.size();i++){
            int num=0;
            for(int j=0;j<grid[0].size();j++){
                num=num*2+grid[i][j];
            }
            result+=num;
        }
        return result;
    }
};
