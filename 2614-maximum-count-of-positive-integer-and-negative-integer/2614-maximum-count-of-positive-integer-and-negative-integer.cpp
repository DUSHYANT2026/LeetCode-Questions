class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pcount = 0; int ncount = 0;
        for(auto it : nums){
            if(it == 0) continue;
            if(it > 0) pcount++;
            else ncount++;
        } 
        return max(pcount,ncount);
    }
};