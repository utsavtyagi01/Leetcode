class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int start=1;
       int end=*max_element(nums.begin(),nums.end());
       int mid=0;
       int add;
       while(start<=end){
           add=0;
           mid=start+(end-start)/2;
           for(int i=0;i<nums.size();i++){
               add+=ceil((double)nums[i]/(double)mid);
           }
           if(add<=threshold){
               end=mid-1;
           }
           else{
               start=mid+1;
           }
       } 
       return start;
    }
};
