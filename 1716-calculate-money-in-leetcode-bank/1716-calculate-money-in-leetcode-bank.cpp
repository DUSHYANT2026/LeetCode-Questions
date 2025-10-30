class Solution {
public:
    int totalMoney(int n) {
        long long ans = 0;

        int count = 0;
        int temp = 0;
        for(int i=1; i<=n; i++){
            int x = i;
            if(x%7 == 0) x = 7;
            else x = x%7;

            cout<<x<<"   "<<x + temp<<endl;
            ans += x + temp;
            count = x;
            if(count == 7){
                count = 0;
                temp++;
            }
        }
        return ans;
    }
};