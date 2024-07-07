class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result=numBottles;

        while(numBottles>=numExchange){
            int remaining=(numBottles/numExchange);
            result+=remaining;
            numBottles=remaining+(numBottles%numExchange);
        }
        return result;
    }
};
