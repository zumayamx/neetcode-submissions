struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node)
    {
        right->prev->next = node;
        node->prev = right->prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right; // LRU
        right->prev = left; // MRU
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->val = value;
        }
        else
        {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(newNode);
            if (cache.size() > cap)
            {
                cache.erase(left->next->key);
                remove(left->next);
            }
        }
    }
};
