// class Solution {
// public:
//     int check(vector<int> nums){
//         sort(nums.begin(),nums.end());
//         return nums[nums.size()-1];
//     }
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         vector<int> temp;
//         for(int i=0; i<k; i++){
//             temp.push_back(nums[i]);
//         }
//         ans.push_back(check(temp));

//         for(int i=k; i<nums.size(); i++){
//             temp.erase(temp.begin());
//             temp.push_back(nums[i]);
//             ans.push_back(check(temp));
//         }
//         return ans;
//     }
// };
















class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i],i});
            if(i+1 >= k){
                while(pq.top().second < (i-k+1)) pq.pop();
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};