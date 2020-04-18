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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* iter = head;

        while (iter != NULL && iter->next != NULL) {
            if (iter->val == iter->next->val) {
                ListNode* nextPoint = iter->next->next;
                while (nextPoint != NULL && iter->val == nextPoint->val) {
                    nextPoint = nextPoint->next;
                }
                iter->next = nextPoint;
            }
            iter = iter->next;
        }

        return head;
    }
};