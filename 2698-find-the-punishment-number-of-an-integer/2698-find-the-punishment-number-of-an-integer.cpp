class Solution {
private:
    bool check(int& i, int sum, int temp){
        if(temp == 0){
            return i == sum;
        }
        int newtemp = 1;
        while(temp/newtemp){
            newtemp *= 10;
            int newsum = sum + temp%newtemp;
            if(check(i,newsum,temp/newtemp)){
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            int temp = i*i;
            if(check(i,0,temp) == true){
                ans += temp;
            }
        }
        return ans;
    }
};