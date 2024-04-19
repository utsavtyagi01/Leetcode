class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int> > result;
        result.push_back({1});
        if(n==1)
        return result;
        result.push_back({1,1});
        if(n==2)
        return result;
        for(int i=2;i<n;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){
                temp.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            temp.push_back(1);
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};
