class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return (k <= numOnes+numZeros) ? min(numOnes,k) : numOnes - (k - numOnes - numZeros);
    }
};