class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0,end=nums[nums.size()-1];
        while(start<=end){
            int count=0;
            int mid = start + (end - start) / 2;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>=mid)
                count++;
            }
            if(count==mid)
            return mid;

            else if(count<mid)
            end=mid-1;
            else if(count>mid)
            start=mid+1;
        }
        return -1;
    }
};
