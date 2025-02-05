class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        vector<int> nums;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                nums.push_back(s1[i]);
                nums.push_back(s2[i]);
            }
        }
        if(nums.size() != 4)
            return false;
        else{
            if(nums[0]==nums[3] && nums[1]==nums[2])
                return true;
        }
        return false;
    }
};