class MyHashSet {
public:
    vector<list<int>> store;
    int size;
    MyHashSet() {
        size=100;
        store.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<int> :: iterator search(int key){
        int i=hash(key);
        return find(store[i].begin(),store[i].end(),key);
    }
    
    void add(int key) {
        if(contains(key))   return;
        int i=hash(key);
        store[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))   return;
        int i=hash(key);
        store[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)!=store[i].end()) return true;
        else return false;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */