// class Solution {
// private:
//     bool isUgly(int n) {
//         if(n<0)
//         return false;
//         int i=n;
//         while(n!=1){
//             if(n%2==0)
//             n=n/2;
//             else if(n%3==0)
//             n=n/3;
//             else if(n%5==0)
//             n=n/5;
//             if(i==n)
//             return false;
//             i=n;
//         }
//         return true;
//     }
// public:
//     int nthUglyNumber(int n) {
//         int count = 0; int ans = 0;
//         for(int i=1; i<INT_MAX; i++){
//             if(isUgly(i) == true){
//                 count++;
//             }
//             if(count == n){
//                 ans = i;
//                 break;
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n);
        nums[0] = 1;
        
        int index2 = 0, index3 = 0, index5 = 0;
        int multiple2 = 2;
        int multiple3 = 3;
        int multiple5 = 5;

        for (int i = 1; i < n; i++) {
            int nextUglyNumber = min({multiple2, multiple3, multiple5});
            nums[i] = nextUglyNumber;

            if (nextUglyNumber == multiple2) {
                index2++;
                multiple2 = nums[index2] * 2;
            }
            if (nextUglyNumber == multiple3) {
                index3++;
                multiple3 = nums[index3] * 3;
            }
            if (nextUglyNumber == multiple5) {
                index5++;
                multiple5 = nums[index5] * 5;
            }
        }
        return nums[n-1];
    }
};
