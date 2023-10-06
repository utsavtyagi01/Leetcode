class Solution {
public:
    int reverse(int x) {
        if(x>(pow(2,31)-1)||x<-pow(2,31))
        return 0;
        int r=0,num=0,temp=-1;;
        if (x<0){
        temp=0;
        }
        while(x!=0){
            if(num>INT_MAX/10||num<INT_MIN/10)
            return 0;
            num=num*10+(x%10);
            x=x/10;
        }
        
        return num;
    }
};
