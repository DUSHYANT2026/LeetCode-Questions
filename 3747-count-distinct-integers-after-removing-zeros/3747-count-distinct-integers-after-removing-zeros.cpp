// class Solution {
// public:
//     bool  check(string s){
//         for(auto it : s){
//             if(it == '0') return false;
//         }
//         return true;
//     }
//     long long dpcheck(long long i, long long n, vector<long long> &dp){
//         if(i > n){
//             return 0;
//         }
//         if(dp[i] != -1) return dp[i];
//         long long count = check(to_string(i)) ? 1 : 0;
//         if(i < n){
//             count  = count + dpcheck(i+1,n,dp);
//         }
//         return dp[n] = count; 
//     }
//     long long countDistinct(long long n) {
//         vector<long long> dp(n+1,-1);
//         return dpcheck(1,n,dp);
//     }
// };



class Solution {
private:
    string S;

    long long memo[20][2];

    long long solve(int pos, bool isTight, bool isNonZeroStarted) {
        if (pos == S.size()) {
            return isNonZeroStarted ? 1 : 0;
        }

        if (!isTight && memo[pos][isNonZeroStarted] != -1) {
            return memo[pos][isNonZeroStarted];
        }

        long long count = 0;
        int limit = isTight ? (S[pos] - '0') : 9;

        for (int d = 0; d <= limit; ++d) {
            
            if (isNonZeroStarted && d == 0) {
                continue;
            }
            
            bool newTight = isTight && (d == limit);
            bool newNonZeroStarted = isNonZeroStarted || (d > 0);

            count += solve(pos + 1, newTight, newNonZeroStarted);
        }

        if (!isTight) {
            memo[pos][isNonZeroStarted] = count;
        }

        return count;
    }

public:
    long long countDistinct(long long n) {
        S = to_string(n);
        for (int i = 0; i < 20; ++i) {
            memo[i][0] = memo[i][1] = -1;
        }
        return solve(0, true, false);
    }
};