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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int counter=0;
        ListNode* init = NULL;

        while(++counter < m) {
            if(init == NULL) init = head;
            else init = init->next;
        }

        // init will be at one spot before m

        ListNode* tmp, * xx, *prev = NULL, *end = (init == NULL) ? head : init->next;

        tmp = end;

        while(counter++ <= n) {
            xx = tmp->next;
            tmp->next = prev;
            prev=tmp;
            tmp=xx;
        }

        if(init == NULL) head = prev;
        else {
            init->next = prev;
        }

        end->next=tmp;
        return head;
    }
};