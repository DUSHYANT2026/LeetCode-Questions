class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto it : arr){
            pq.push({abs(it-x),it});
        }
        while(!pq.empty() && k--){
            auto it = pq.top(); pq.pop();
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};