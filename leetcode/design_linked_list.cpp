class LNode {
public:
    int val;
    LNode* next;

    LNode(int _val) : val(_val), next(NULL) {};
    LNode(int _val, LNode* _next) : val(_val), next(_next) {};
};

class MyLinkedList {
private:
    LNode* head = NULL;
    LNode* tail = NULL;
    int size=0;

    LNode* at(int index) {
        LNode* iter = head;
        int count = 0;
        while(count < index && iter != NULL) {
            iter = iter->next;
            count++;
        }
        return iter;
    }
public:
    /** Initialize your data structure here. */
    MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size) return -1;
        else {
            auto node = at(index);
            return node->val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LNode* newHead = new LNode(val, head);
        head = newHead;
        if(head->next == NULL) tail = head;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(size == 0) addAtHead(val);
        else {
            LNode* newTail = new LNode(val);
            tail->next = newTail;
            tail = newTail;
            size++;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0) addAtHead(val);
        else if(index == size) addAtTail(val);
        else if(index > size) return;
        else {
            auto prev = at(index-1);
            LNode* node = new LNode(val);
            node->next = prev->next;
            prev->next= node;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= 0 && index < size) {
            LNode* toDelete = NULL;
            if(index == 0) {
                toDelete = head;
                head = head->next;
            } else {
                auto prev = at(index-1);
                auto toDelete = prev->next;
                prev->next= toDelete->next;

                // correct tail
                if(index == size-1) tail = prev;
            }

            size--;
            delete toDelete;
        }
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