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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=n-1;
        ListNode *prev=head, *rem=head, *temp = head;
        while(c--) {
            temp = temp->next;
        }
        
        while(temp->next != NULL) {
            prev=rem;
            rem=rem->next;
            temp=temp->next;
        }
        
        if(prev == rem && prev == temp) head = NULL;
        else if(rem == head) head = head->next;
        else prev->next = rem->next;

        return head;
    }
};