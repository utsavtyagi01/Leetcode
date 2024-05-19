class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0,count=0,temp=LLONG_MAX;
        for(auto i:nums){
            long long ans=i^k;
            if(ans>i){
                sum+=ans;
                count++;
                temp=min(temp,ans-i);
            }
            else{
                sum+=i;
                temp=min(temp,i-ans);
            }
        }
        if(count%2==0)
        return sum;
        return (sum-temp);
    }
};
