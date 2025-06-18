class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& nums, int k) {
        vector<int> ans;
        priority_queue<int> pq;

        for(int i = 0; i < nums.size(); ++i) {
            pq.push( abs(nums[i][0]) + abs(nums[i][1]));
            if(pq.size() > k) pq.pop();
            if(pq.size() == k) ans.push_back(pq.top());
            else ans.push_back(-1);
        }
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> resultsArray(vector<vector<int>>& nums, int k) {
//         vector<int> ans;
//         vector<long long> pq;

//         for(int i=0; i<nums.size(); i++){
//             pq.push_back(abs(nums[i][0]) + abs(nums[i][1]));
//             sort(pq.begin(),pq.end());
//             if(pq.size() < k) ans.push_back(-1);
//             else{
//                 ans.push_back(pq[k-1]);
//             }
//         }
//         return ans;
//     }
// };