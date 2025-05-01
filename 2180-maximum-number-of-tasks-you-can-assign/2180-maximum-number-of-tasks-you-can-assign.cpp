class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) {
            int p = pills;
            multiset<int> st;
            for (int i = m - mid; i < m; ++i) {
                st.insert(workers[i]);
            }

            for (int i = mid - 1; i >= 0; --i) {
                auto it = prev(st.end());
                if (*it >= tasks[i]) {
                    st.erase(it);
                } else {
                    if (p == 0) return false;
                    auto rep = st.lower_bound(tasks[i] - strength);
                    if (rep == st.end()) return false;
                    st.erase(rep);
                    --p;
                }
            }
            return true;
        };

        int left = 1, right = min(n, m), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};