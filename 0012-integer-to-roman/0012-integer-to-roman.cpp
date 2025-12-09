class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums;

        string s = to_string(num);
        int n = s.size();
        for(int i=0; i<n; i++){
            nums.push_back((s[i]-'0') * pow(10,n-1-i));
        }
        string ans = "";
        for(auto it : nums){
            int temp = it;
            cout<<it<<endl;
            while(temp >= 1000){
                ans += 'M';
                temp -= 1000;
            }
            while(temp >= 900){
                ans += "CM";
                temp -= 900;
            }
            while(temp >= 800){
                ans += "DCCC";
                temp -= 800;
            }
            while(temp >= 700){
                ans += "DCC";
                temp -= 700;
            }
            while(temp >= 600){
                ans += "DC";
                temp -= 600;
            }
            while(temp >= 500){
                ans += 'D';
                temp -= 500;
            }
            while(temp >= 400){
                ans += "CD";
                temp -= 400;
            }
            while(temp >= 300){
                ans += "CCC";
                temp -= 300;
            }
            while(temp >= 200){
                ans += "CC";
                temp -= 200;
            }
            while(temp >= 100){
                ans += "C";
                temp -= 100;
            }
            while(temp >= 90){
                ans += "XC";
                temp -= 90;
            }
            while(temp >= 80){
                ans += "LXXX";
                temp -= 80;
            }
            while(temp >= 70){
                ans += "LXX";
                temp -= 70;
            }
            while(temp >= 60){
                ans += "LX";
                temp -= 60;
            }
            while(temp >= 50){
                ans += 'L';
                temp -= 50;
            }
            while(temp >= 40){
                ans += "XL";
                temp -= 40;
            }
            while(temp >= 30){
                ans += "XXX";
                temp -= 30;
            }
            while(temp >= 20){
                ans += "XX";
                temp -= 20;
            }
            while(temp >= 10){
                ans += 'X';
                temp -= 10;
            }
            while(temp >= 9){
                ans += "IX";
                temp -= 9;
            }
            while(temp >= 8){
                ans += "VIII";
                temp -= 8;
            }
            while(temp >= 7){
                ans += "VII";
                temp -= 7;
            }
            while(temp >= 6){
                ans += "VI";
                temp -= 6;
            }
            while(temp >= 5){
                ans += "V";
                temp -= 5;
            }
            while(temp >= 4){
                ans += "IV";
                temp -= 4;
            }
            while(temp >= 3){
                ans += "III";
                temp -= 3;
            }
            while(temp >= 2){
                ans += "II";
                temp -= 2;
            }
            while(temp >= 1){
                ans += 'I';
                temp -= 1;
            }
        }
        return ans;
    }
};