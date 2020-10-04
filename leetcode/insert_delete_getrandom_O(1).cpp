class RandomizedSet {
private:
    map<int, int> mm;
    vector<int> vv;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mm.find(val) == mm.end()) {
            vv.push_back(val);
            mm.insert({val, vv.size()-1});
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mm.find(val) != mm.end()) {
            int index = mm[val];
            mm[vv[vv.size()-1]] = index;
            mm.erase(val);
            vv[index] = vv[vv.size()-1];
            vv.pop_back();
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
