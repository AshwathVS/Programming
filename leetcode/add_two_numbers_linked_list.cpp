/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *iter = NULL;
        int remainder = 0, total = 0;

        while(l1 != NULL && l2 != NULL) {
            total = l1->val + l2->val + remainder;
            remainder = total/10;

            if(head == NULL) {
                head = new ListNode(total % 10);
                iter = head;
            } else {
                iter->next = new ListNode(total % 10);
                iter = iter->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* ll = (l1 == NULL) ? l2 : l1;
        while(ll != NULL) {
            total = ll->val + remainder;
            remainder = total / 10;
            iter->next = new ListNode(total % 10);
            iter = iter->next;
            ll = ll->next;
        }

        if(remainder != 0)  {
            iter->next = new ListNode(remainder);
        }
        
        return head;
    }
};