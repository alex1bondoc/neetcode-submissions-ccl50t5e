class LRUCache {
    int capacity;
    std::list<int> used;
    std::unordered_map<int, std::pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.contains(key)) {
            return -1;
        }
        used.erase(cache[key].second);
        used.push_back(key);
        cache[key].second = --used.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) cache.erase(key);
        else if (used.size() == capacity) {
            int val{used.front()};
            used.erase(used.begin());
            cache.erase(val);
        }
        used.push_back(key);
        cache[key] = {value, --used.end()};
    }
};
