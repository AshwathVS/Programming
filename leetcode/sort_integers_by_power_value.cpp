class Solution {
public:
    map<int, int> store;
    
    int getSteps(int x) {
        if(x == 1) return 0;

        if(store.find(x) != store.end()) return store.at(x);
        else {
            int steps = 0; 
            if(x % 2 == 0) 
                steps = 1 + getSteps(x/2);
            else
                steps = 1 + getSteps(3*x + 1);

            store[x] = steps;

            return steps;
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> powers;
        int i=lo;
        while(i <= hi) {
            powers.push_back({getSteps(i), i});
            i++;
        }
        
        sort(powers.begin(), powers.end());
        return powers[k - 1].second;
    }
};