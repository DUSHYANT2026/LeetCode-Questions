class Solution {
public:
    int minimumFlips(int n) {
        string ans = "";

        while(n != 0){
            ans += n%2 + '0';
            n = n/2;
        }
        string temp = ans;
        reverse(temp.begin(),temp.end());

        int count = 0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i] != temp[i]) count++;
        }
        return count;
    }
};