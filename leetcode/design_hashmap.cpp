class MyHashMap {
private:
    int size = 0, max_size = 1000;
    vector<list<pair<int, int>> > store;

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
        vector<list<pair<int, int>>> tmp(max_size);
        for (int i = 0; i < store.size(); i++) {
            if (!store[i].empty()) {
                for (auto val : store[i]) {
                    int hashVal = hash(val.first);
                    tmp[hashVal].push_back(val);
                }
            }
        }

        store = tmp;
    }

    list<pair<int, int>>::iterator find(list<pair<int, int>>::iterator start, list<pair<int, int>>::iterator end, int key) {
        while(start != end) {
            if(start->first == key) return start;
            start++;
        }
        return end;
    }

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        store = vector<list<pair<int, int>> >(max_size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashVal = hash(key);
        if(store[hashVal].empty()) {
            store[hashVal].push_back({key, value});
        } else {
            auto it = find(store[hashVal].begin(), store[hashVal].end(), key);
            if(it == store[hashVal].end()) {
                store[hashVal].push_back({key, value});
                size++;
            } else {
                it->second = value;
            }
        }

        checkSpaceAndTriggerResize();
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashVal = hash(key);
        if(store[hashVal].empty()) {
            return -1;
        } else {
            auto it = find(store[hashVal].begin(), store[hashVal].end(), key);
            if(it != store[hashVal].end()) {
                return it->second;
            } else {
                return -1;
            }
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
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
};