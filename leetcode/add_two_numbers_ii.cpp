class Solution {    
public:
    
    int len(ListNode* ll) {
        if(ll == NULL) return 0;
        int count=1;
        while(ll != NULL) {
            ll = ll->next;
            count++;
        }
        return count;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = len(l1);
        int len2 = len(l2);
        
        /**
            If there is len difference, append zeroes to the list with lesser length
            l1 = 1->2->3->4 
            l2 = 2->3

            then l2 will become 0->0->2->3
        */
        if(len1 != len2) {
            ListNode* head = new ListNode(0), *iter = head;
            int numZero = abs(len1-len2);
            while(--numZero > 0) {
                iter->next = new ListNode(0);
                iter = iter->next;
            }
            
            if(len1 > len2) {
                iter->next = l2;
                l2 = head;
            } else {
                iter->next = l1;
                l1 = head;
            }
        }

        auto res = add(l1, l2);
        if(res.second != 0) {
            return new ListNode(res.second, res.first);
        } else {
            return res.first;
        }
    }
    
    pair<ListNode*, int> add(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) {
            return {NULL, 0};
        } else if(l1 != NULL && l2 != NULL) {
            auto res = add(l1->next, l2->next);
            int total = l1->val + l2->val + res.second;
            return {new ListNode(total % 10, res.first), total/10};
        } else {
            ListNode* ll = (l1 == NULL) ? l2 : l1;
            ListNode* head = new ListNode(ll->val), * iter = head;
            while(ll->next != NULL) {
                iter->next = new ListNode(ll->next->val);
                iter = iter->next;
                ll = ll->next;
            }
            
            return {head, 0};
        }
    }
};