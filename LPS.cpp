class Solution {
public:
    int lcs(string s1, string s2){
        int n=s1.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];

                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};
