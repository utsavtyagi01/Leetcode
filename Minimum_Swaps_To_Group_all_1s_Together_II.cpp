class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=0;

        for(int i:nums){
            if(i)
            ones++;
        }
        int temp=0,mini=INT_MAX;
        for(int i=0;i<ones;i++){
            if(nums[i]==0)
            temp++;
        }
        mini=min(mini,temp);
        for(int i=ones;i<nums.size()+ones;i++){
            if(i-1>=0){
                if(nums[i-ones]==0)
                temp--;
            }
            if(nums[i%nums.size()]==0)
            temp++;

             mini=min(mini,temp);
        }
        return mini;
    }
};
