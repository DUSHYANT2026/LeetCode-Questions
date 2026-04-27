// class Solution {
// public:
//     bool isvowels(char ch){
//         if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'  || ch == 'u') return true;
//         return false;
//     }
//     string sortVowels(string s) {
//         int counta = 0, counte = 0, counti = 0, counto = 0, countu = 0;
//         for(int i=0; i<s.size(); i++){
//             int it  = s[i];
//             if(isvowels(it)){
//                if(it == 'a') counta++;
//                if(it == 'e') counte++;
//                if(it == 'i') counti++;
//                if(it == 'o') counto++;
//                if(it == 'u') countu++;
//             }
//         }
//         vector<pair<pair<int,int>, char>> nums;
//         for(int i=0; i<s.size(); i++){
//             if(isvowels(s[i])){
//                 if(s[i] == 'a') nums.push_back({{counta, i}, 'a'});
//                 else if(s[i] == 'e') nums.push_back({{counte, i}, 'e'});
//                 else if(s[i] == 'i') nums.push_back({{counti, i}, 'i'});
//                 else if(s[i] == 'o') nums.push_back({{counto, i}, 'o'});
//                 else if(s[i] == 'u') nums.push_back({{countu, i}, 'u'});
//             }
//         }

//         auto comp = [](pair<pair<int,int>, char>& a, pair<pair<int,int>, char> &b){
//             if(a.first.first == b.first.first) return a.first.second < b.first.second && a.second < b.second;
//             return a.first.first > b.first.first;
//         };

//         sort(nums.begin(), nums.end(), comp);

//         int idx = 0;

//         for(int i=0; i<s.size(); i++){
//             if(isvowels(s[i])){
//                 s[i] = nums[idx].second;
//                 idx++;
//             }
//         }
//         return s;
//     }
// };


class Solution {
public:
    bool isvowels(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    string sortVowels(string s) {
        int counta=0, counte=0, counti=0, counto=0, countu=0;
        int firstA=-1, firstE=-1, firstI=-1, firstO=-1, firstU=-1;

        for(int i=0; i<s.size(); i++){
            if(isvowels(s[i])){
                if(s[i]=='a'){ counta++; if(firstA==-1) firstA=i; }
                if(s[i]=='e'){ counte++; if(firstE==-1) firstE=i; }
                if(s[i]=='i'){ counti++; if(firstI==-1) firstI=i; }
                if(s[i]=='o'){ counto++; if(firstO==-1) firstO=i; }
                if(s[i]=='u'){ countu++; if(firstU==-1) firstU=i; }
            }
        }

        vector<pair<pair<int,int>, char>> nums;
        for(int i=0; i<s.size(); i++){
            if(isvowels(s[i])){
                if(s[i]=='a')      nums.push_back({{counta, firstA}, 'a'});
                else if(s[i]=='e') nums.push_back({{counte, firstE}, 'e'});
                else if(s[i]=='i') nums.push_back({{counti, firstI}, 'i'});
                else if(s[i]=='o') nums.push_back({{counto, firstO}, 'o'});
                else if(s[i]=='u') nums.push_back({{countu, firstU}, 'u'});
            }
        }
        auto comp = [](pair<pair<int,int>, char>& a, pair<pair<int,int>, char>& b){
            if(a.first.first != b.first.first) return a.first.first > b.first.first;
            return a.first.second < b.first.second;
        };

        sort(nums.begin(), nums.end(), comp);

        int idx = 0;
        for(int i=0; i<s.size(); i++){
            if(isvowels(s[i])){
                s[i] = nums[idx].second;
                idx++;
            }
        }
        return s;
    }
};