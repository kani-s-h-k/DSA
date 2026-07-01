struct Node{
    int key,value;
    Node* next, *prev;

    Node(int key1,int value1){
        key = key1;
        value = value1;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    Node* head = new Node(-1,-1), *tail = new Node(-1,-1);
    unordered_map<int,Node*> mpp;
    int capacity;

    void insertAfterHead(Node* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void deletion(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear();
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        else{
            Node* node = mpp[key];
            deletion(node);
            insertAfterHead(node);
            return node->value;
        }
    }
    
    void put(int key, int val) {
        if(capacity==0) return;
        if(mpp.find(key)==mpp.end()){
            if(mpp.size()==capacity){
                Node* node = tail->prev; 
                deletion(node);
                mpp.erase(node->key);
                delete node;
            }
            Node* node = new Node(key,val);
            insertAfterHead(node);
            mpp[key] = node;
            return;
        }
        Node* node = mpp[key];
        deletion(node);
        insertAfterHead(node);
        node->value = val;
    }
};