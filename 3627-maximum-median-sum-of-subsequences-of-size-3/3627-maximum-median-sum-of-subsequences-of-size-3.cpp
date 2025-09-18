class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int x = nums.size()/3;
        priority_queue<int> pq1; 
        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i=0; i<x; i++){
            cout<<nums[i]<<endl;
            pq2.push(nums[i]);
        }
        for(int i=x; i<nums.size(); i++) pq1.push(nums[i]);

        long long ans = 0;
        while(!pq1.empty() && !pq2.empty()){
            long long x = pq1.top(); pq1.pop();
            long long y = pq1.top(); pq1.pop();
            long long z = pq2.top(); pq2.pop();
            vector<long long> temp = {x,y,z};
            sort(temp.begin(),temp.end());
            ans += temp[1];
        }
        return ans;

    }
};