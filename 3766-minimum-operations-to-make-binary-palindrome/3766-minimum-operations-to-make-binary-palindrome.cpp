class Solution {
public:
    bool check(int n){
        string ans = "";
        while(n != 0){
            ans += n%2 + '0';
            n /= 2;
        }
        string temp = ans;
        reverse(temp.begin(),temp.end());
        return ans == temp;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            if(check(nums[i])) ans.push_back(0);
            
            else {
                int x = nums[i]; int y = nums[i];
                while(true){
                    x++; y--;
                    if(check(x)){ ans.push_back(x - nums[i]); break;}
                    else if(check(y)){ ans.push_back(nums[i] - y); break;}

                }
            }
        }
        return ans;
    }
};