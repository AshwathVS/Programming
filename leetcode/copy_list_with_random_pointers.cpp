class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        map<Node*, Node*> m;

        Node* iter = head;
        Node* cloneHead = new Node(iter->val);
        Node* cloneTmp = cloneHead;

        while(iter != NULL) {
            // set random of clone to iter
            cloneTmp->random = iter;

            // create a new node for clone with tmp val;
            if(iter->next != NULL) {
                cloneTmp->next = new Node(iter->next->val);
            } else {
                cloneTmp->next = NULL;
            }

            m.insert({iter, cloneTmp});

            // assign iter = tmp
            iter = iter->next;
            cloneTmp = cloneTmp->next;
        }

        cloneTmp = cloneHead;

        while(cloneTmp != NULL) {
            cloneTmp->random = cloneTmp->random->random == NULL ? NULL : m[cloneTmp->random->random];
            cloneTmp = cloneTmp->next;
        }
        return cloneHead;
    }
};