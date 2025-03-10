class Solution {
public:
    int countVowelSubstrings(string word) {
        string vowels = "aeiou";
        int count=0;
        for(int i=0; i<word.size(); i++){
            set<char> s;
            for(int j=i; j<word.size(); j++){
                s.insert(word[j]);
                string news="";
                for(auto it : s){
                    news += it;
                }
                if(news == vowels){
                    count++;
                }
            }
        }
        return count;
    }
};