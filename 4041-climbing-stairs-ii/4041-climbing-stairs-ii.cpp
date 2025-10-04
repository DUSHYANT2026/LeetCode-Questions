class Solution {
private:
    int dp[100001];
    int dpcheck(int index, int n, vector<int> &cost){
        if(index == n){
            return 0;
        }
        if(index > n) return 1e8;

        if(dp[index] != -1) return dp[index];
        int count1 =  1e9, count2 = 1e9, count3 = 1e9;
        if(index+1<=n){
            count1 = (cost[index] + 1)  + dpcheck(index+1,n,cost);
        }
        if(index+2<=n){
            count2 = (cost[index+1] + 4)  + dpcheck(index+2,n,cost);
        }
        if(index+3<=n){
            count3 = (cost[index+2] + 9)  + dpcheck(index+3,n,cost);
        }

        return dp[index] = min(count1, min(count2,count3));
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return dpcheck(0,n,costs);
    }
};


// class Solution {
// public:
//     int dp[100001];
//     int solve(int i,int n,vector<int>& costs){
//         if(i==n) return 0;
//         if(i>n) return 1e8;
//         if(dp[i]!=-1) return dp[i];
//         int one=1e9,two=1e9,three=1e9;
//         if(i+1<=n){
//             one = (costs[i] + 1) + solve(i+1,n,costs);
//         }
//        if(i+2 <= n){
//          two = (costs[i+1] + 4) + solve(i+2,n,costs);
//        }
//        if(i+3 <= n){
//             three = (costs[i+2]+9) + solve(i+3,n,costs);
//        }

//        return dp[i] = min(one,min(two,three));
//     }
//     int climbStairs(int n, vector<int>& costs) {
//         memset(dp,-1,sizeof(dp));
//         return solve(0,n,costs);
//     }
// };