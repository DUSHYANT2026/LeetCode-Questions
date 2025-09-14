class Solution {
private:
    bool dpcheck(string &s, int i, int j, string &t) {
        if (j < 0) return true;  
        if (i < 0) return false; 

        if (s[i] == t[j]) {
            return dpcheck(s, i - 1, j - 1, t); 
        }
        return dpcheck(s, i - 1, j, t);
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < words.size(); i++) {
            string temp = words[i];
            int m = temp.size();
            if (dpcheck(s, n - 1, m - 1, temp)) {
                count++;
            }
        }
        return count;
    }
};




