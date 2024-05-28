class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int cost[n];
        for(int i=0;i<n;i++){
            cost[i]=abs((s[i]-'a')-(t[i]-'a'));
        }
        int j=0,sum=0,result=0;
        for(int i=0;i<n;i++){
            if(sum+cost[i]<=maxCost)
            sum+=cost[i];
            else{
                result=max(result,i-j);
                while(sum+cost[i]>maxCost){
                    sum-=cost[j];
                    j++;
                }
                sum+=cost[i];
            }
        }
        return max(result,n-j);
    }
};
