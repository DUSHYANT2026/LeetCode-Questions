class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        vector<string> nums;

        string temp;
        while(ss >> temp){
            nums.push_back(temp);
        }
        for(auto it : nums){
            cout<<it<<endl;
        }
        return nums.size();
    }
};