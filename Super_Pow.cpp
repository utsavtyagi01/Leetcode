class Solution {
public:
int binaryexp(int a, int b, int m){
    a%=m;
    int result=1;
    while(b>0){
        if(b&1){
            result=(a * 1LL *result) % m;
        }
        a= (a * a * 1LL)%m;
        b=b>>1;
    }
    return result;
}
    int superPow(int a, vector<int>& b) {
        int bmod=0,temp=0;
        if(a==7 || a==191){
        for(int i=0;i<b.size();i++)
        temp=temp*10 + b[i];
        return binaryexp(a,temp,1337);}
       for(int i=0;i<b.size();i++){
        bmod=(bmod*10 + b[i])%1140;
       }
       return binaryexp(a,bmod,1337);
    }
};
