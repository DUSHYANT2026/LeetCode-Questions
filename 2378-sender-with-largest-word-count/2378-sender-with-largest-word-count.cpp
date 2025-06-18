class Solution {
public:
    int convert(vector<string> &nums){
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            string s = nums[i];
            vector<string> newnums;
            istringstream ss(s);
            string temp = "";
            while(ss >> temp){
                newnums.push_back(temp);
            } 
            ans += newnums.size();
        }
        return ans;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        unordered_map<string,vector<string>> mapp;
        for(int i=0; i<senders.size(); i++){
            mapp[senders[i]].push_back(messages[i]);
        }
        vector<pair<int,string>> nums;
        for(auto it : mapp){
            nums.push_back({convert(it.second),it.first});
        }
        sort(nums.rbegin(),nums.rend());
        return nums[0].second;
    }
};