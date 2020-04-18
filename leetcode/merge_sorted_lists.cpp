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
        ListNode* result = NULL;
        ListNode* head = NULL;
        
        while (true) {
            
            if (l1 == NULL && l2 == NULL) {
                break;
            }
            else if (l1 == NULL) {
                while(l2 != NULL) {
                    int val = l2->val;
                    if (result == NULL) {
                        result = new ListNode(val);
                        head = result;
                    } else {
                        result->next = new ListNode(val);
                        result = result->next;
                    }
                    l2 = l2->next;
                }
            } else if (l2 == NULL) {
                while(l1 != NULL) {
                    int val = l1->val;
                    if (result == NULL) {
                        result = new ListNode(val);
                        head = result;
                    } else {
                        result->next = new ListNode(val);
                        result = result->next;
                    }
                    l1 = l1->next;
                }
            } else {
                int val;
                if (l1->val < l2->val) {
                    val = l1->val;
                    l1 = l1->next;
                } else {
                    val = l2->val;
                    l2 = l2->next;
                }
                
                if (result == NULL) {
                    result = new ListNode(val);
                    head = result;
                } else {
                    result->next = new ListNode(val);
                    result = result->next;
                }
            }
        }
        
        
        return head;
    }
};