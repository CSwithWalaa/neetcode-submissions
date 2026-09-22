class LRUCache {
// get(), put() _ O(1) time
// O(capacity) space

private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) 
            : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    // Remove node from list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right before tail
    void insert(Node* node) {
        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) 
            return -1;

        Node* node = cache[key];

        // Mark as recently used
        remove(node);
        insert(node);

        return node->value;
    }
    
    void put(int key, int value) {

        // Key already exists
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;

            // Move to MRU (most recently used)
            remove(node);
            insert(node);

            return;
        } 
        
        // Create new node
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        // Capacity exceeded
        if(cache.size() > capacity) {
            Node* lru = head->next;
            remove(lru);

            cache.erase(lru->key);
            delete lru;
        }    
    }
};
