class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int i=0,j=0;
     int b=0,a=0;
     for(int i=0;i<nums.size()-1;i++)
    {
        b=nums[i];
        for(int j=1;j<nums.size();j++)
        {
            if(b+nums[j]==target)
                break;
        }

    }
    return {i,j};
    }
};
