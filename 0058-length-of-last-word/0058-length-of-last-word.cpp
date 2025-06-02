class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> nums;
        istringstream s1(s);

        string temp;

        while(s1 >> temp){
            nums.push_back(temp);
        }
        return nums[nums.size()-1].size();
    }
};