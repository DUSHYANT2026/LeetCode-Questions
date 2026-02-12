class Solution {
private:
    bool check(vector<int>& nums){
        int mini = INT_MAX; int maxi = INT_MIN; 
        for(auto it : nums){
            if(it != 0){ maxi = max(maxi,it); mini = min(mini,it);}
        }
        return mini == maxi;
    }
public:
    int longestBalanced(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            vector<int> nums(26,0);
            for(int j=i; j<s.size(); j++){
                nums[s[j] - 'a']++;
                if(check(nums)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};