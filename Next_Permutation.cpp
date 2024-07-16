class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int i=n;
        while(i>0 && nums[i-1] >= nums[i])
        i--;

        if(i>0){
        int j=i;

        while(j<=n && nums[i-1]<nums[j]){
            j++;
        }        

        swap(nums[i-1],nums[j-1]);
        }
        reverse(nums.begin()+i,nums.end());
        
    }
};
