class Solution {
private:
    bool check(int n, vector<int> &nums){
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;

        while(n != 0){
            int x = n%10;
            if(mapp.find(x) == mapp.end() || mapp[x] == 0) {
                return false;
            }
            if(mapp.find(x) != mapp.end()){
                mapp[x]--; 
            }
            n = n/10;
        }
        return true;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        for(int i=100; i<=999; i++){
            if(check(i,digits)  && i%2 == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};