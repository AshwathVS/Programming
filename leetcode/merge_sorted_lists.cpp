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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL, *iter=NULL;
        
        while(l1 != NULL || l2 != NULL) {
            int val;
            if(l1 == NULL) {
                val = l2->val;
                l2 = l2->next;
            } else if(l2 == NULL) {
                val = l1->val;
                l1 = l1->next;
            } else {
                if(l1->val <= l2->val) {
                    val = l1->val;
                    l1 = l1->next;
                } else {
                    val = l2->val;
                    l2 = l2->next;
                }
            }
            
            if(iter == NULL) {
                iter = new ListNode(val);
                head = iter;
            } else {
                iter->next = new ListNode(val);
                iter = iter->next;
            }
        }
        
        return head;
    }
};
