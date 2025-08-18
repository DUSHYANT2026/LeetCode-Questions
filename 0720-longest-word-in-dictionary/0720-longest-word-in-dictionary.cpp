class Solution {
public:
    string longestWord(vector<string>& words) {

        unordered_map<string,int> mapp;
        for(auto it : words) mapp[it]++;

        vector<pair<int,string>> nums;
        for(int i=0; i<words.size(); i++){
            string temp = words[i];
            int count = 0;
            string ntemp = "";
            for(int j=0; j<temp.size(); j++){
                ntemp += temp[j];
                if(mapp.find(ntemp) != mapp.end()){
                    count++;
                }
                else {
                    nums.push_back({count,temp});
                    break;
                }
            }
            if(count != 0){
                nums.push_back({count,words[i]});
            }
        } 
        auto coustom = [](pair<int,string> & a, pair<int,string> &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        sort(nums.begin(),nums.end(), coustom);
        for(auto it : nums){
            cout<<it.first<<" "<<it.second<<endl;
        }
        return (nums[0].first == 0) ? "" : nums[0].second;
    }
};