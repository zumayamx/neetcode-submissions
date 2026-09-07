struct Node {
    int val;
    Node* next = nullptr;

    Node(int x) : val(x) {}
};

class MyLinkedList {
    Node* head;
    Node* tail;
    int size;

   public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        if (head == nullptr) return -1;

        Node* currNode = head;
        for (int i = 0; i < index; i++) {
            currNode = currNode->next;
        }

        return currNode->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if (head != nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }

        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (tail != nullptr) {
            tail->next = newNode;
            tail = tail->next;
        } else {
            head = newNode;
            tail = newNode;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) return addAtHead(val);
        if (index == size) return addAtTail(val);
        if (index > size) return;

        Node* currNode = head;
        for (int i = 1; i < index; i++) {
            currNode = currNode->next;
        }

        Node* newNode = new Node(val);

        newNode->next = currNode->next;
        currNode->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (head == nullptr) return;

        if (index == 0) {
            head = head->next;
            if (size == 1) tail = nullptr;
        } else {
            Node* currNode = head;
            for (int i = 1; i < index; i++) {
                currNode = currNode->next;
            }
            currNode->next = currNode->next->next;
            if (index == size - 1) tail = currNode;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */