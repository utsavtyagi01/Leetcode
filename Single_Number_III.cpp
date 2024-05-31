class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0,temp=0;
        for(int i:nums)
        xorr^=i;

        while(((xorr>>temp)&1)!=1)
        temp++;

        int zero_bucket=0,one_bucket=0;
        for(int i:nums){
            if((i>>temp)&1){
                one_bucket^=i;
            }
            else{
                zero_bucket^=i;
            }
        }
        return {zero_bucket,one_bucket};

    }
};
