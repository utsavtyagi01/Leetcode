class Solution {
public:
    int func(vector<int>& nums,int i, int j,vector<vector<int>> &dp){
        if(i>j)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];
        long long maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            long long cost=nums[k]*nums[i-1]*nums[j+1];
            cost+=func(nums,i,k-1,dp);
            cost+=func(nums,k+1,j,dp);
            maxi=max(maxi,cost);
        }

        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return func(nums,1,nums.size()-2,dp);
    }
};
