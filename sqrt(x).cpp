#include<math.h>
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
        return x;
        int start=1;
        int end=x;
        int mid=0;
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid==x/mid)
            return mid;
            else if(mid>x/mid)
            end=mid-1;
            else
            start=mid+1;
        }
        return end;
        
    }
};
