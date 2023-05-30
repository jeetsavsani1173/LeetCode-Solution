class MyHashSet {
public:
    int hash[1000008]={0};
    MyHashSet() {
        // int hash[1000008]={0};
        
    }
    
    void add(int key) {
        hash[key]=1;
    }
    
    void remove(int key) {
        hash[key]=0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */