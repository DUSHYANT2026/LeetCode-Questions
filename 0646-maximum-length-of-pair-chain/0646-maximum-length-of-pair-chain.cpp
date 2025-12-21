class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
        int count = 0;
        auto custom = [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        };
        sort(nums.begin(),nums.end(),custom);
        int mark = nums[0][1];
        for(int i=1; i<nums.size(); i++){
            if((mark < nums[i][0])){ count++; mark = nums[i][1];}
        }
        return count + 1;
    }
};