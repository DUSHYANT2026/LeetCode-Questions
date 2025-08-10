class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        // do{
        //     // while(n != 1){
        //     //     if(n%2 != 0){
        //     //         return false;
        //     //     }
        //     //     n = n/2;
        //     // }
        // }while(n = next_permutation(n));

            while(n != 1){
                if(n%2 != 0){
                    return false;
                }
                n = n/2;
            }

        return true;
    }
};