class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool match0 = false;
        bool match1 = false;
        bool match2 = false;

        for (auto triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            if (triplet[0] == target[0]) {
                match0 = true;
            }
            if (triplet[1] == target[1]) {
                match1 = true;
            }
            if (triplet[2] == target[2]) {
                match2 = true;
            }
            
            if (match0 && match1 && match2) {
                return true;
            }
        }

        return match0 && match1 && match2;
    }
};