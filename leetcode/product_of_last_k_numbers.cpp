class ProductOfNumbers {
public:
    vector<int> vv;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) vv.clear();
        else {
            if(vv.size() == 0) vv.push_back(num);
            else vv.push_back(vv[vv.size()-1] * num);
        }
    }
    
    int getProduct(int k) {
        if(k > vv.size()) return 0;
        else if(k == vv.size()) return vv[vv.size()-1];
        else return vv[vv.size()-1]/vv[vv.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */