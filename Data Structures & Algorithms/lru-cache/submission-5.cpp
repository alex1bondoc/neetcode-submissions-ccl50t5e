class LRUCache {
    int capacity;
    std::list<int> used;
    std::unordered_map<int, std::pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.contains(key)) return -1;
        auto it{cache[key].second};
        used.erase(it);
        used.push_back(key);
        cache[key].second = --used.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) used.erase(cache[key].second);
        else if (cache.size() == capacity) {
            int lru{used.front()};
            used.pop_front();
            cache.erase(lru);
        }
        used.push_back(key);
        cache[key] = {value, --used.end()};
    }
};
