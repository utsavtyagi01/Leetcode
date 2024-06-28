class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> edges(n,0);
        for(vector<int> it:roads){
            edges[it[0]]++;
            edges[it[1]]++;
        }

        long long result=0;
        sort(edges.begin(),edges.end());
        for(long long i=0;i<n;i++){
            result+=(i+1)*edges[i];
        }
        return result;
    }
};
