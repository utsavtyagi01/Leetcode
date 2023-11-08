class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        if(nums.size()==1)
        return nums[start];
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid==0){
                if(nums[mid]==nums[mid+1])
                mid=mid+2;
                else
                return nums[mid];
            }
            if(mid==nums.size()-1){
                if(nums[mid]==nums[mid-1])
                mid=mid-2;
                else
                return nums[mid];
            }
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
            return nums[mid];
            if(mid%2==0){
                if(nums[mid]==nums[mid-1]){
                    end=mid-2;
                }
                else 
                start=mid+1;
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    start=mid+1;
                }
                else
                end=mid-2;
            }
        }

        return nums[start];
    }
};
