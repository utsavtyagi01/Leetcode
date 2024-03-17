/*
So in this code , we have to count the number of steps we had to take to Reach the nth step We could either take a step or two step. 
So if we are on the ith step, then. it could be possible. Either we would have taken the one step from (i-1) stair or (two steps from i-2) steps.
WWe could possibly use the recursion, but its time complexity would be exponential. So we will use dynamic programming for reducing redundant calculations 
cause we are just calculating the previous calculations.
So we will just make a array, and we will keep adding I - 1 and I - 2 values to. calculate the current value.
*/class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
        
    }
};
