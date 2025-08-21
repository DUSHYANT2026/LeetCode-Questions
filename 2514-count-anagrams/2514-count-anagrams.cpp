#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        long long mod = 1e9 + 7;
        return power(n, mod - 2);
    }

    int countAnagrams(string s) {
        long long mod = 1e9 + 7;
        vector<long long> fact(s.length() + 1);
        fact[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        stringstream ss(s);
        string word;
        long long ans = 1;

        while (ss >> word) {
            int n = word.length();
            map<char, int> counts;
            for (char c : word) {
                counts[c]++;
            }

            long long num = fact[n];
            long long den = 1;
            for (auto const& pair : counts) {
                den = (den * fact[pair.second]) % mod;
            }

            long long word_ans = (num * modInverse(den)) % mod;
            ans = (ans * word_ans) % mod;
        }

        return (int)ans;
    }
};