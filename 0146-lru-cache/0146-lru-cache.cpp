class LRUCache {
private:
    int capacityFull = 0;
    list<pair<int, int>> li;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
public:
    LRUCache(int capacity) {
        capacityFull = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        auto i = mp[key];
        auto value = i->second;
        li.erase(i);
        li.push_front({key,value});
        mp[key]=li.begin();
        return value;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            li.erase(mp[key]);
            li.push_front({key, value});
            mp[key] = li.begin();
            return;
        }
        if(capacityFull == 0) {
            auto x = li.back().first;
            mp.erase(x);
            li.pop_back();
            capacityFull++;
        }
        capacityFull--;
        li.push_front({key,value});
        mp[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */