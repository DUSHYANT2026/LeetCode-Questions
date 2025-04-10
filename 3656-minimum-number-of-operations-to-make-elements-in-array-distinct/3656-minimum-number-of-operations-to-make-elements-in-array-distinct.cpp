class Solution {
private:
    bool check(vector<int> &nums){
        unordered_map<int,int> mapp;
        for(auto it : nums) mapp[it]++;
        return mapp.size() < nums.size();
    }
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        int maxi = nums.size()/3  + 3;

        while(maxi--){
            vector<int> temp;
            for(auto it : nums) temp.push_back(it);
            if(check(temp) == true && temp.size() > 2){
                nums.erase(nums.begin(), nums.begin() + 3);
                count++;
            }
            else if(check(temp) == true){
                nums.clear();
                count++; break;
            }
        }
        return count;
    }
};