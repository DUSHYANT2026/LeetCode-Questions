class Solution {
public:
    string converttobinary(int n){
        string ans = "";
        while(n != 0){
            ans += '0' + n%2; 
            n = n/2;
        }
        return ans;
    }
    int converttonumber(string s){
        int ans = 0;
        reverse(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') ans += pow(2,i);
        }
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<nums.size(); i++){
            string temp1 = converttobinary(nums[i]);
            int check = converttonumber(temp1);
            pq.push({check,nums[i]});
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};