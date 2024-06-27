class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int i=0,j=0,k=0,l=0;
        i=edges[0][0];
        j=edges[0][1];
        k=edges[1][0];
        l=edges[1][1];

        if(i==l || i==k)
        return i;
        if(j==k || j==l)
        return j;
        
        return 0;
    }
};
