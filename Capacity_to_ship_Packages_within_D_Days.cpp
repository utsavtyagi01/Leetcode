class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*max_element(weights.begin(),weights.end());
        int end=accumulate(weights.begin(),weights.end(),0);
        int mid=0,day=0;
        long long wt=0;
        while(start<=end){
            mid=start+(end-start)/2;
            wt=0;
            day=0;
            for(int i=0;i<weights.size();i++){
                wt+=weights[i];
                if(i+1<weights.size()&&wt+weights[i+1]>mid){
                    wt=0;
                    day++;
                }
            }
            if(day+1<=days){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};
