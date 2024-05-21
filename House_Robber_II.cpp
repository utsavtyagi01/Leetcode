class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int> sum1(nums.size(),0);
        vector<int> sum2(nums.size(),0);

        int n=nums.size()-1;

        for(int i=0;i<=n-1;i++){
            if(i==0)
            sum1[i]=nums[i];
            else if(i==1)
            sum1[i]=max(nums[i],sum1[i-1]);
            else{
                sum1[i]=max(nums[i]+sum1[i-2],sum1[i-1]);
            }
        }

        for(int i=1;i<=n;i++){
            if(i==1)
            sum2[i]=nums[i];
            else if(i==2)
            sum2[i]=max(nums[i],sum2[i-1]);
            else{
                sum2[i]=max(nums[i]+sum2[i-2],sum2[i-1]);
            }
        }

        return max(sum1[n-1],sum2[n]);
    }
};
