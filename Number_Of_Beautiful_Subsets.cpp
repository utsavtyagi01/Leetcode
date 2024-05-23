class Solution {
public:
    int func(vector<int>& nums,int i,vector<int> & mp,int k){
       if(i==nums.size())
       return 1;
       int taken=0,nottaken=0;
       if(nums[i]-k < 0 || mp[nums[i]-k]==0){
        mp[nums[i]]++;
        taken = func(nums,i+1,mp,k);
        mp[nums[i]]--;
       }
       nottaken=func(nums,i+1,mp,k);
       return taken+nottaken;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> mp(1001,0);
        sort(nums.begin(),nums.end());
        return func(nums,0,mp,k)-1;
       }
};
