class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        
        istringstream ss(caption);
        vector<string> nums; 
        string temp;
        while(ss >> temp){
            nums.push_back(temp);
        }
        if(nums.size() == 0) return "#";
        nums[0][0] = tolower(nums[0][0]);
        for(int j = 1; j<nums[0].size(); j++){
                nums[0][j] = tolower(nums[0][j]);
        }
        ans += nums[0];
        for(int i=1; i<nums.size(); i++){
            if(ans.size() > 100) break;
            if(i == 0) continue;
            else nums[i][0] = toupper(nums[i][0]);
            for(int j = 1; j<nums[i].size(); j++){
                nums[i][j] = tolower(nums[i][j]);
            }
            
            ans += nums[i];
        }
        if(ans.size() > 100){
            return ans.substr(0,100);
        }
        
        return ans;
    }
};