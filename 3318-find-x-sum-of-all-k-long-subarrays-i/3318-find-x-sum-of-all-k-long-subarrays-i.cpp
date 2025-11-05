class Solution {
private:
    int xsum(vector<int> &nums, int x){
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;

        int sum = 0; int count = 1; int ans = 0;
        priority_queue<pair<int,int>> pq;
        for(auto it : mapp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty() && x!=0){
            auto it = pq.top().second; 
            int time = pq.top().first; pq.pop();
            while(time--){
                sum += it;
            }
            x--;
        }
        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<=n-k; i++){
            vector<int> temp;
            int sum = 0;
            for(int j=i; j<i+k; j++){
                temp.push_back(nums[j]);
            }
            sum = xsum(temp,x);
            ans.push_back(sum);
        }
        return ans;
    }
};

