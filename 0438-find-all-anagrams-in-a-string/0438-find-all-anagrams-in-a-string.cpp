// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         if(p.size() > s.size()) return {};

//         int size = p.size();
//         sort(p.begin(),p.end());
//         vector<int> ans;

//         for(int i=0; i<s.size()-size+1; i++){
//             string temp = s.substr(i,size);
//             sort(temp.begin(),temp.end());
//             if(temp == p){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        
        vector<int> result;
        vector<int> pCount(26, 0);
        vector<int> windowCount(26, 0);
        
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        int windowSize = p.size();
        
        for (int i = 0; i < windowSize; i++) {
            windowCount[s[i] - 'a']++;
        }
        
        if (pCount == windowCount) {
            result.push_back(0);
        }
        
        for (int i = windowSize; i < s.size(); i++) {
            windowCount[s[i] - 'a']++;
            windowCount[s[i - windowSize] - 'a']--;
            
            if (pCount == windowCount) {
                result.push_back(i - windowSize + 1);
            }
        }
        
        return result;
    }
};