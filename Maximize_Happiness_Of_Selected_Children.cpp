class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long result=0;
        for(int i=0;i<k;i++){
            if(i==0){
                result+=happiness[i];
                continue;
            }
            if(happiness[i]-i>=0)
            result+=happiness[i]-i;
        }
        return result;
    }
};
