class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0,sum=0;
        for(int i:nums)
        totalsum+=i;
        if(totalsum%2!=0) return false;
        sum=totalsum/2;
        int n=nums.size();
          vector<vector<bool> > dp(n,vector<bool> (sum+1 ,false));
    for(int j=0;j<n;j++)
    dp[0][j]=false;
    for(int i=0;i<n;i++)
    dp[i][0]=true;

    

    for(int i=1;i<n;i++){
        for(int target=1;target<=sum;target++){
            if(nums[i-1]<=target){
                dp[i][target]=dp[i-1][target-nums[i-1]]||dp[i-1][target];
            }
            else
                dp[i][target]=dp[i-1][target];
        }
    }
    return dp[n-1][sum];
    }
};
