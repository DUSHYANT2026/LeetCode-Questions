class Solution {
private:
    int checksum(int n){
        int ans = 0;
        while(n != 0){
            ans += n%10;
            n = n/10;
        }
        return ans;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mapp;
        for(int i=1; i<=n; i++){
            mapp[checksum(i)]++;
        }
        int maxi = 0;
        for(auto it : mapp){
            if(it.second > maxi){
                maxi = it.second;
            }
        }
        int ans = 0;
        for(auto it : mapp){
            if(it.second == maxi) ans++;
        }
        return ans;
    }
};