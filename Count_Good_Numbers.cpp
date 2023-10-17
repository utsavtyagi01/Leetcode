int mod=1000000007;
long long func(long long a,long long b){
        if(b==0)
        return 1;

        if(b%2==0){
            return func((a*a)%mod,b/2)%mod;
        }

        else{
            return a*func((a*a)%mod,b/2)%mod;
        }

    
}
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long even=n/2+n%2;
        long long odd=n-even;

        return( func(5,even)*func(4,odd))%mod;
       
    }
};
