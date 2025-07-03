class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string ans = ""; 
        int n = s.size();
        vector<int> nums(n+1,0);
        for(auto it : shifts){
            int l = it[0]; int r = it[1]; int mark = it[2];
            if(mark == 1){ nums[l] += 1; nums[r+1] -= 1; }
            else { nums[l] -= 1; nums[r+1] += 1; }
        }
        int it = 0;
        for(int i=0; i<n; i++){
            it += nums[i];
            int temp = ((it%26) + 26)%26;
            s[i] = 'a' + ((s[i] - 'a' + temp) % 26);
        }
        return s;
    }
};