// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         auto custom =[](string a, string b){
//             return a.size() < b.size();
//         };
//         sort(strs.begin(),strs.end(),custom);
//         int count = 0;

//         for(auto it : strs){
//             int count0 = 0; int count1 = 0;
//             for(auto i : it){
//                 if(i == '1') count1++;
//                 else count0++;
//             }
//             if(n >= count1 && m >= count0){
//                 count++;
//                 n -= count1;
//                 m -= count0;
//             }
//             else{
//                 break;
//             }
//         }
//         return count;
//     }
// };




class Solution {
public:
    pair<int,int> check(string temp){
        int count1 = 0; int count0 = 0;
        for(auto it : temp){
            if(it == '1') count1++;
            else count0++;
        }
        return {count1,count0};
    }
    int dpcheck(int index, int n, int m, vector<string> &strs, vector<vector<vector<int>>> &dp){

        if(index < 0) return 0;

        if(dp[index][n][m] != -1) return dp[index][n][m];              // use dp according to variables
        pair<int,int> nums = check(strs[index]);
        int x = nums.first; int y = nums.second;
        int count = 0; 
        if(n >= x && m >= y){
            count = 1 + dpcheck(index-1, n-x, m-y,strs,dp);
        }
        int notcount = dpcheck(index-1, n,m, strs,dp);

        return dp[index][n][m] = max(count,notcount);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>> (n+1, vector<int> (m+1, -1)));

        return dpcheck(size-1,n,m,strs,dp);
    }
};







