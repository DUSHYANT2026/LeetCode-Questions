class Solution {
private:
    static bool compare(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(),intervals.end(),compare);
        
        int count = 1;
        int check = intervals[0][1]; 
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= check) {
                count++;
                check = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};