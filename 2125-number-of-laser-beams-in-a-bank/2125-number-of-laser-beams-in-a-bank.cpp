class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int x = 0;
        for(auto it : bank){
            int count = 0;
            for(auto i : it){
                if(i == '1') count++;
            }
            if(count){
                ans += count*x;
                x = count;
            }
        }
        return ans;
    }
};