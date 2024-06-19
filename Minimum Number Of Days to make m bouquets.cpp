class Solution {
public:
    bool helper(int m,int k, vector<int> bloomDay,int mid){
        
            int temp=0,flower=0;
        for(int i=0;i<bloomDay.size();i++){
               if(bloomDay[i]<=mid){
                flower++;
                if(flower==k){
                    temp++;
                    flower=0;
                }
               }
               else 
               flower=0;
            }
            if(temp>=m)
            return true;
            else
            return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long)(long)bloomDay.size()<(long)(long)m * (long)(long)k)
        return -1;
        int start=0,end=*max_element(bloomDay.begin(),bloomDay.end());
        int mid= start + (end-start)/2;
        while(start<=end){
            
            mid= start + (end-start)/2;

            
            if(helper(m,k,bloomDay,mid))
            end=mid-1;
            
            else
            start=mid+1;
        }
        return start;
    }
};
