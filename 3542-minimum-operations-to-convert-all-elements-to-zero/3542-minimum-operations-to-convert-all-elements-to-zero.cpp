class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        stack<int> s;
        for(auto it : nums){
            while(!s.empty() && s.top() > it){
                s.pop();
            }
            if(it == 0) continue;
            if(s.empty() || s.top() < it){
                count++;
                s.push(it);

            }
        }
        return count;
    }
};