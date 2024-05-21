class Solution {
public:
    int rob(vector<int>& nums) {
      vector<int> sum(nums.size(),0);
      for(int i=0;i<nums.size();i++){
        if(i==0)
        sum[i]=nums[i];
        else if(i==1)
        sum[i]=max(nums[i-1],nums[i]);
        else{
            sum[i]=max(sum[i-1],sum[i-2]+nums[i]);
        }
      }
      return sum[nums.size()-1];

    }
};
