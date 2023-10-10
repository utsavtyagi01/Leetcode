class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*(long long)k>bloomDay.size())
        return -1;
        int start=0,end=*max_element(bloomDay.begin(),bloomDay.end()),mid=0,bouquet=0;
        while(start<=end){
            int adj=0;
            bouquet=0;
            mid=start+(end-start)/2;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    adj++;
                }
                else
                adj=0;
                if(adj==k){
                    bouquet++;
                    adj=0;
                }
            }
            if(bouquet>=m){
                end=mid-1;
            }
            else if(bouquet<m){
                start=mid+1;
            }
        }
        return start;
        
    }
};
