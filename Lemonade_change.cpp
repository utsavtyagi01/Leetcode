class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int five=0,ten=0;
      for(auto &it:bills){
            if(it==5){
                five++;
            }
            else if(it==10){
                ten++;
                if(five>0)
                five--;
                else
                return false;
            }
            else if(it==20){
                if(ten>0 && five>0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else
                return false;
            }
      }
      return true;
    }
};
