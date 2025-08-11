class Solution {
public:
    int getMinSwaps(string num, int k) {
        int count = 0;

        string ans = "";
        string pre = num;

        do{
            if(count == k){
                ans = num;
                break;
            }
            count++;
        }while(next_permutation(num.begin(),num.end()));
        cout<<ans;

        int i = 0; int j = 0; int pount = 0; 
        while (i < num.size()) {
            j = i;
            while (pre[j] != ans[i]) j++;
			
            while (i < j) {
                swap(pre[j], pre[j-1]);
                j--;
                pount++;
            }
            i++;
        }
        return pount;
    }
};