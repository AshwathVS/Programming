class Solution {
public:
    int climbStairs(int n) {
        map<int, int> store;
        store[1] = 1;
        store[2] = 2;
        return recurse(n, store);
    }
    
    int recurse(int n, map<int, int>& store) {
        
            if (store.find(n) != store.end()) {
                return store[n];
            } else {
                int ret = recurse(n - 1, store) + recurse(n - 2, store);
                store[n] = ret;
                return ret;
            }
        
    }
};