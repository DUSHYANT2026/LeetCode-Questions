class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
    unordered_map<int, int> full_freq;
    for (int num : nums) {
        full_freq[num]++;
    }
    int n = nums.size();
    int dominant_element = -1;
    for (auto const& [val, count] : full_freq) {
        if (count * 2 > n) {
            dominant_element = val;
            break;
        }
    }
    if (dominant_element == -1) {
        return -1;
    }

    unordered_map<int, int> prefix_freq;
    vector<pair<int, int>> pre(n);
    int max_freq = 0;
    int max_elem = -1;
    for (int i = 0; i < n; ++i) {
        prefix_freq[nums[i]]++;
        if (prefix_freq[nums[i]] > max_freq) {
            max_freq = prefix_freq[nums[i]];
            max_elem = nums[i];
        }
        pre[i] = {max_freq, max_elem};
    }

    unordered_map<int, int> suffix_freq;
    vector<std::pair<int, int>> sur(n);
    max_freq = 0;
    max_elem = -1;
    for (int i = n - 1; i >= 0; --i) {
        suffix_freq[nums[i]]++;
        if (suffix_freq[nums[i]] > max_freq) {
            max_freq = suffix_freq[nums[i]];
            max_elem = nums[i];
        }
        sur[i] = {max_freq, max_elem};
    }

    for (int i = 0; i < n - 1; ++i) {
        int prefix_len = i + 1;
        int suffix_len = n - (i + 1);
        
        if (pre[i].second == dominant_element && pre[i].first * 2 > prefix_len) {
            if (sur[i + 1].second == dominant_element && sur[i + 1].first * 2 > suffix_len) {
                return i;
            }
        }
    }

    return -1;
    }
};