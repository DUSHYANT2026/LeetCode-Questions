class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(result, used, n, 0);
        return result;
    }

private:
    bool backtrack(vector<int>& ans, vector<bool>& vis, int n, int ind) {
        while (ind < ans.size() && ans[ind] != 0) {
            ind++;
        }
        if (ind == ans.size()) {
            return true;
        }

        for (int i = n; i >= 1; i--) {
            if (vis[i]) continue;

            if (i == 1) {
                ans[ind] = 1;
                vis[1] = true;
                if (backtrack(ans, vis, n, ind + 1)) return true;
                ans[ind] = 0;
                vis[1] = false;
            } else if (ind + i < ans.size() && ans[ind + i] == 0) {
                ans[ind] = i;
                ans[ind + i] = i;
                vis[i] = true;
                if (backtrack(ans, vis, n, ind + 1)) return true;
                ans[ind] = 0;
                ans[ind + i] = 0;
                vis[i] = false;
            }
        }
        return false;
    }
};