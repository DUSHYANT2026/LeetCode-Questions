class ProductOfNumbers {
public:
    vector<int>pr={1};
    int n=1;
    ProductOfNumbers() {
       pr.reserve(40000);
    }
    
    void add(int num) {
       if(num==0){
        pr={1};
        n=1;
       }
       else{
        pr.push_back(pr[n++-1]*num);
       }
    }
    
    int getProduct(int k) {
        if(n<=k)
            return 0;
        return pr[n-1]/pr[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */