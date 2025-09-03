class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> mapp;
        sort(hand.begin(), hand.end());
        for (auto it : hand) {
            mapp[it]++;
        }
        for (auto it : hand) {
            if (mapp[it] <= 0) {
                continue;
            }
            for (int j = it; j < it + groupSize; j++) {
                if (mapp[j] <= 0) {
                    return false;
                }
                mapp[j]--;
            }
        }
        return true;
    }
};
