class RandomizedSet {
public:
    unordered_map<int, bool> items;

    RandomizedSet() {
        items.clear();
    }
    
    bool insert(int val) {
        bool had = items.count(val);
        items[val] = true;
        return !had;
    }
    
    bool remove(int val) {
        bool had = items.count(val);
        if (had) items.erase(val);
        return had;
    }
    
    int getRandom() {
        auto it = items.begin();
        std::advance(it, rand() % items.size());
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
