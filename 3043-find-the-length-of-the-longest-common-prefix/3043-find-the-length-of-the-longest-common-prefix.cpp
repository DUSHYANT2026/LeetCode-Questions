class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mapp;
        for(auto it : arr1){
            string s = to_string(it);
            for(int i=0; i<s.size(); i++){ mapp[s.substr(0,i+1)] = s.substr(0,i+1).size(); }
        }

        int ans = 0;
        for(int i=0; i<arr2.size(); i++){
            string s = to_string(arr2[i]);
            for(int j=0; j<s.size(); j++){
                if(mapp.find(s.substr(0,j+1)) != mapp.end()) ans = max(ans, mapp[s.substr(0,j+1)]);
            }
        }
        return ans;
    }
};