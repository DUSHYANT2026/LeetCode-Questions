class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int checkleft = 0; int checkright = 0;
        for(auto it : left){
            checkleft = max(checkleft, it);
        }
        for(auto it : right){
            checkright = max(checkright, n-it);
        }
        return max(checkleft, checkright);
    }
};