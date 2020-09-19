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
    ListNode* swapPairs(ListNode* head) {
        return flip(head);
    }
    
    ListNode* flip(ListNode* A) {
        if(A == NULL) return NULL;
        else if(A->next == NULL) return A;
        else {
            ListNode* B = A->next;
            ListNode* tmp = flip(B->next);
            B->next = A;
            A->next = tmp;
            return B;
        }
    }
};