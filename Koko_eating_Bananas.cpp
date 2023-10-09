class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=*max_element(piles.begin(),piles.end()),mid=0;
        long long time=0;
            while(start<=end){
                time=0;
                mid=start+(end-start)/2;
                for(int i=0;i<piles.size();i++){
                    time+=ceil(((double)piles[i]/(double)mid));
                    }
                if(time<=h){
                    end=mid-1;
                }
                else if(time>=h)
                start=mid+1;

                }
            return start;

    }
};
