class Solution {
private:
    vector<string> convert(string s) {
        vector<string> ans;
        istringstream ss(s);
        string temp = "";
        while (ss >> temp) {
            ans.push_back(temp);
        }
        return ans;
    }
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, int> mapp1, mapp2;
        for (auto it : positive_feedback) mapp1[it]++;
        for (auto it : negative_feedback) mapp2[it]++;

        vector<pair<int, int>> pq;

        for (int i = 0; i < report.size(); i++) {
            vector<string> nums = convert(report[i]);
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (mapp1.find(nums[j]) != mapp1.end()) sum += 3 * mapp1[nums[j]];
                if (mapp2.find(nums[j]) != mapp2.end()) sum -= 1 * mapp2[nums[j]];
            }
            pq.push_back({sum, student_id[i]});
        }

        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; 
            }
            return a.first > b.first; 
        };

        sort(pq.begin(), pq.end(), compare);

        vector<int> ans;
        for (int i = 0; i < k && i < pq.size(); i++) {
            ans.push_back(pq[i].second);
        }
        return ans;
    }
};