
class Solution {
public:
    string longestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
        int k=0;
        int max=0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s[i-1]==t[j-1]){
                    
                dp[i][j]=dp[i-1][j-1] + 1;
                int originalIndex = i - dp[i][j];
                    int reversedIndex = s.size() - j;
                    if (originalIndex == reversedIndex) {
                        if (dp[i][j] > max) {
                            max = dp[i][j];
                            k = i - 1;
                        }
                    }
                }
            }
        }

        return s.substr(k - max + 1, max);
        
    }
};
