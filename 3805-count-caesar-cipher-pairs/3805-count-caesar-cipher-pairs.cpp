class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        map<vector<long long>, long long> mapp;
        for(auto it : words){
            vector<long long> nums;
            for(int i=0; i<it.size()-1; i++){
                int temp = (it[i]-it[i+1])%26;
                if(temp < 0) temp = temp + 26;
                nums.push_back(temp);
            }
            for(auto it : nums){
                cout<<it<<" ";
            }
            cout<<endl;
            mapp[nums]++;
        }
        for(auto it : mapp){
            cout<<it.second<<endl;
            ans += (it.second * (it.second-1))/2;
        }
        return ans;
    }
};