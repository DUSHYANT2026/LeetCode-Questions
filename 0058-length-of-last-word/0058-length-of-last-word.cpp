class Solution {
public:
    int lengthOfLastWord(string s) {
        // vector<string> nums;
        // istringstream s1(s);

        // string temp;

        // while(s1 >> temp){
        //     nums.push_back(temp);
        // }
        // return nums[nums.size()-1].size();


        reverse(s.begin(),s.end());
        string ans = "";
        int mark = 0;
        for(int i=0; i<s.size(); i++){
            if(i == 0 && s[i] == ' '){
                while(s[i] == ' '){
                    i++;
                }
            }
            mark = i; break;
        }
        cout<<mark<<endl;
        for(int i=mark; i<s.size(); i++){
            if(s[i] != ' '){
                ans += s[i];
            }
            else{
                break;
            }
        }
        return ans.size();
    }
};