class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> mm;
    list<int> ll;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mm.find(key) != mm.end()) {
            pushToFront(key);
            return mm[key].first;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if(mm.find(key) == mm.end()) {
            if(capacity == mm.size()) removeLeastAccessedKey();
            ll.push_front(key);
            mm.insert({key, {value, ll.begin()}});
        } else {
            pushToFront(key);
            mm[key].first = value;
        }
        
    }

    void removeLeastAccessedKey() {
        int key = ll.back();
        mm.erase(key);
        ll.pop_back();
    }
    
    void pushToFront(int key) {
        auto pp = mm[key];
        ll.erase(pp.second);
        ll.push_front(key);
        mm[key].second = ll.begin();
    }

};