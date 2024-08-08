class Solution {
public:
    int func(vector<int> &cuts,int i,int j,vector<vector<int>> &dp){
        if(i+1==j)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        long long mini=INT_MAX;
        for(int k=i+1;k<j;k++){
            long long cost=cuts[j]-cuts[i];
            int left=0,right=0;
            if(dp[i][k]!=-1)
            left=dp[i][k];
            else
            left=func(cuts,i,k,dp);

            if(dp[k][j]!=-1)
            right=dp[k][j];
            else
            right=func(cuts,k,j,dp);

            cost+=left;
            cost+=right;
            mini=min(mini,cost);
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return func(cuts,0,m-1,dp);
    }
};
