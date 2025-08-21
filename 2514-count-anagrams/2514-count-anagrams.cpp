class Solution {
public:
    int countAnagrams(string s) {
        vector<int> nums;
        stringstream ss(s);

        vector<string> ans;
        string temp = "";
        while(ss >> temp){
            ans.push_back(temp);
        }
   
        for(auto it : ans){
            sort(it.begin(),it.end());
            set<string> x;
            do{
                x.insert(it);
            }while(next_permutation(it.begin(),it.end()));
            nums.push_back(x.size());
        }
long long mod = 1000000007;
long long count = 1;
for(auto it : nums) {
    count = (count * it) % mod;
}
return count;
    }
};