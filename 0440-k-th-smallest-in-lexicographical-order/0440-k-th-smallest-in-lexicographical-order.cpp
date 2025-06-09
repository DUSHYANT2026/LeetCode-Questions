// class Solution {
// public:
//     int findKthNumber(int n, int k) {
//         vector<string> nums;
//         for(int i=1; i<=n; i++) nums.push_back(to_string(i));
//         sort(nums.begin(),nums.end());
//         return stoi(nums[k-1]);
//     }
// };


class Solution {
public:
    int findKthNumber(int n, int k) {
        long long current = 1;
        k--;
        while (k > 0) {
            long long steps = calculateSteps(n, current, current + 1);
            if (steps <= k) {
                current += 1;
                k -= steps;
            } else {
                current *= 10;
                k -= 1;
            }
        }
        return current;
    }
    
private:
    long long calculateSteps(int n, long long n1, long long n2) {
        long long steps = 0;
        while (n1 <= n) {
            steps += min((long long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};