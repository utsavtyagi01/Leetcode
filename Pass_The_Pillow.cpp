class Solution {
public:
    int passThePillow(int n, int time) {
        if(n>time)
        return time+1;
       

        if((time/(n-1))%2==0){
        return (1+(time%(n-1)));
        }

        if((time/(n-1))%2!=0)
            return (n-(time%(n-1)));

        return 0;
    }
};
