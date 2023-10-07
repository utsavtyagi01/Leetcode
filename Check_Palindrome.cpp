class Solution {
public:
    bool isPalindrome(int x) {
        long long y=0,rem=0,num=0;
        if(x>=0){
        y=x;
        while(x!=0){
            rem=x%10;
            x=x/10;
            num=num*10+rem;
        }
        if(y==num)
        return true;

        else
        return false;}

        else
        return false;
    }
};
