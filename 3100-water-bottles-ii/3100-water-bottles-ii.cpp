class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;

        int change = numExchange;
        int bottle = numBottles;

        while(bottle >= change){
            count++;
            bottle = bottle-change;
            change = change + 1;
            bottle++;
        }
        return numBottles + count;
    }
};