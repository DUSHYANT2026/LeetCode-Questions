class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0; int left = 0;
        while(numBottles > 0){
            ans += numBottles;
            left += numBottles;
            numBottles = (left/numExchange);
            left = left%numExchange;
        }
        return ans;
    }
};