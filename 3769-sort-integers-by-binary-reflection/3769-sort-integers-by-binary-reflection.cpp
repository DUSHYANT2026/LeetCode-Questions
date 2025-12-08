// class Solution {
// public:
//     int check(int n){
//         int ans = 0;
//         string s = "";
//         while(n != 0){
//             s += '0' + n%2; 
//             n = n/2;
//         }
//         reverse(s.begin(),s.end());
//         for(int i=0; i<s.size(); i++){
//             if(s[i] == '1') ans += pow(2,i);
//         }
//         return ans;
//     }
//     vector<int> sortByReflection(vector<int>& nums) {
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         for(int i=0; i<nums.size(); i++){
//             pq.push({check(nums[i]),nums[i]});
//         }
//         vector<int> ans;
//         while(!pq.empty()){
//             ans.push_back(pq.top().second); pq.pop();
//         }
//         return ans;
//     }
// };


// Dan4Life
// O(n log n)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) begin(a),end(a)

using ll = long long;
using vi = vector<int>;
using ar2 = array<int,2>;
using ar3 = array<int,3>;

const int mxN = (int)3e5+10;
const int INF = (int)1e9+10;
const ll LINF = (ll)4e18+10;
const int MOD = (int)1e9+7;

class Solution {
public:
    int reflect(int x) {
        int r = 0;
        while (x) {
            r = (r << 1) | (x & 1);
            x >>= 1;
        }
        return r;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> v;
        v.reserve(sz(nums));
        for (int x : nums) v.emplace_back(reflect(x), x);
        sort(all(v), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        vector<int> ans;
        ans.reserve(sz(nums));
        for (auto &p : v) ans.pb(p.second);
        return ans;
    }
};