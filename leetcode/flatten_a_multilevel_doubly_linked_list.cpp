/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


class Solution {
private:
    Node* last = NULL;
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        else {
            last = head;
            if(head->child) {
                flatten(head->child);
                Node* nextTmp = head->next;
                head->next = head->child;
                head->child->prev = head;
                last->next = nextTmp;
                if(nextTmp != NULL) {
                    nextTmp->prev = last;
                }
                head->child = NULL;
                flatten(nextTmp);
            } else {
                flatten(head->next);
            }
        }

        return head;
    }
};