class RandomizedSet {
private:
    set<int> ss;
    vector<int> vv;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(ss.find(val) == ss.end()) {
            vv.push_back(val);
            ss.insert(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(ss.find(val) != ss.end()) {
            ss.erase(val);
            vv.erase(find(vv.begin(), vv.end(), val));
            return true;
        }

        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int randInt = rand() % vv.size();
        return vv[randInt];
    }
};
