class Cashier {
private:
    map<int, int> store;
    int count=0;
    int n;
    int discount;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        
        for(int i=0; i<products.size(); i++) {
            store.insert({products[i], prices[i]});
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double billAmount = 0;

        count++;
        count = count % n;
        
        for(int i=0; i<product.size(); i++) {
            billAmount += (amount[i]*store[product[i]]);
        }
        
        if(count == 0) {
            billAmount = billAmount - ((discount*billAmount)/100);
        } 

        return billAmount;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */