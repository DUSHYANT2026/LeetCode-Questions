class Solution {
public:
    int check(int n){
        int ans = 0;
        string s = "";
        while(n != 0){
            s += '0' + n%2; 
            n = n/2;
        }
        reverse(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') ans += pow(2,i);
        }
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({check(nums[i]),nums[i]});
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};