class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1; i<=n; i++){
            int temp = i; bool mark = false;
            while(temp != 0){
                int r = temp%10;
                if(r == 2 || r == 5 || r == 6 || r == 9) mark = true;
                if(r == 3 || r == 4 || r == 7){ mark = false; break; }
                temp = temp/10;
            }
            if(mark) count++;
        }
        return count;
    }
};