
class MyHashSet {
private:

    int hash(int key) {
        return key % max_size;
    }

    void checkSpaceAndTriggerResize() {
        if(size == max_size) {
            resize();
        }
    }

    void resize() {
        max_size *= 2;
        vector<list<int>> tmp(max_size);
        for(int i=0; i<store.size(); i++) {
            if(!store[i].empty()) {
                for(int val : store[i]) {
                    int hashVal = hash(val);
                    tmp[hashVal].push_back(val);
                }
            }
        }

        store = tmp;
    }
public:
    /** Initialize your data structure here. */
    vector<list<int>> store;
    int size = 0, max_size = 1000;

    MyHashSet() {
        store = vector<list<int>>(max_size);
    }

    void add(int key) {
        int hashVal = hash(key);
        if(store[hashVal].empty()) {
            store[hashVal].push_back(key);
        } else {
            auto it = find(store[hashVal].begin(), store[hashVal].end(), key);
            if(it == store[hashVal].end()) {
                store[hashVal].push_back(key);
                size++;
            }
        }

        checkSpaceAndTriggerResize();
    }

    void remove(int key) {
        int hashVal = hash(key);
        if(!store[hashVal].empty()) {
            auto it = find(store[hashVal].begin(), store[hashVal].end(), key);
            if(it != store[hashVal].end()) {
                store[hashVal].erase(it);
                size--;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashVal = hash(key);
        if(store[hashVal].empty()) {
            return false;
        } else {
            auto it = find(store[hashVal].begin(), store[hashVal].end(), key);
            return it != store[hashVal].end();
        }
    }
};