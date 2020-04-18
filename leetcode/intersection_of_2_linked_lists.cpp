/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> _set;
        while(headA != NULL) {
            _set.insert(headA);
            headA = headA->next;
        }
        
        while(headB != NULL) {
            if (_set.find(headB) != _set.end()) {
                return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
    }
};