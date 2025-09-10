// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
        
//         vector<string> nums;
//         sort(words.begin(),words.end());
//         do{
//             string temp = "";
//             for(auto it : words) temp += it;
//             nums.push_back(temp);
//         }while(next_permutation(words.begin(),words.end()));


//        vector<int> ans;
//        for(auto it : nums) {
//            int pos = s.find(it, 0);
//            while(pos != string::npos){
//                 ans.push_back(pos);
//                 pos = s.find(it, pos + 1);
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
vector<int>ans;
    vector<int> findSubstring(string s, vector<string>& words) {
        
        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return ans;

        unordered_map<string, int> wordsMap;
        for (const string& word : words) {
            wordsMap[word]++;
        }

        // There are wordLen different starting points
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> windowMap;
            int count = 0;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordsMap.count(word)) {
                    windowMap[word]++;
                    count++;

                    while (windowMap[word] > wordsMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                         ans.push_back(left);
                    }
                } else {
                    // Not a valid word, reset window
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};