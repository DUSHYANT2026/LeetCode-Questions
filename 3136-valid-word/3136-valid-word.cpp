class Solution {
public:
    bool isValid(string word) {
        
        bool mark1 = false; bool marko = false; bool markc = false;
        for(auto it : word){
            if(isdigit(it)){
                continue;
            }
            else if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'){
                marko = true;
            }else if( it == '@' || it == '$' || it == '#'){
                return false;
            }
            else{
                markc = true;
            }
        }
        return (marko && markc && word.size() > 2);
    }
};