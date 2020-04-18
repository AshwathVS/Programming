class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator> > _cache;
    list<int> _lru;
    int _capacity;
public:
    LRUCache(int capacity){
        _capacity = capacity;
    }
    
    void put(int key, int value){
        auto item = _cache.find(key);
        if(item != _cache.end()){
            pushToRecent(item);
            if(item->second.first != value){
                _cache[key] = {value, _lru.begin()};
            }
        }
        else{
            if(_capacity == _cache.size()){
                _cache.erase(_lru.back());
                _lru.pop_back();
            }
            _lru.push_front(key);
            _cache[key] = {value, _lru.begin()};
            
        }
    }
    
    int get(int key){
        auto item = _cache.find(key);
        if(item != _cache.end()){
            pushToRecent(item);
            return item->second.first;
        }
        else{
            return -1;
        }
    }
    
    void pushToRecent(unordered_map<int, pair<int, list<int>::iterator> >::iterator it){
        _lru.erase(it->second.second);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }
    
    void print(){
        unordered_map<int, pair<int, list<int>::iterator> >::iterator it;
        for(it = _cache.begin(); it != _cache.end(); it++){
            cout << it->first << " : " << it->second.first << endl;
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */