class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    Node* head;
    Node* last;
    unordered_map<int, Node*> mp;
    int c;
    LRUCache(int capacity) {
        c = capacity;
        head = new Node(0, 0);
        last = new Node(0,0);
        head->next = last;
        last->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* tmp = mp[key];
        remove(tmp);
        insert(tmp);
        return tmp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) 
            remove(mp[key]);
        if(mp.size() == c)
            remove(last->prev);
        Node* newNode = new Node(key, value);
        insert(newNode);
    }
    void remove(Node* node){
        mp.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node){
        mp[node->key] = node;
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */