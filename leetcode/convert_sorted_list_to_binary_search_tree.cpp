/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* getMiddle(ListNode* start) {
        if(start == NULL) return NULL;
        else {
            ListNode* fast = start, *slow = start, *prev=NULL;
            while (fast->next != NULL) {
                if(fast->next->next != NULL) {
                    fast = fast->next->next;
                } else fast = fast->next;

                prev = slow;
                slow = slow->next;
            }


            if(prev != NULL) prev->next = NULL;

            return slow;
        }

    }

    TreeNode* recurse(ListNode* start) {
        if(start == NULL) return NULL;
        else {
            ListNode* middle = getMiddle(start);
            TreeNode* root = new TreeNode(middle->val);

            if(start == middle) return root;

            root->right = recurse(middle->next);
            root->left = recurse(start);
            return root;
        }

    }

    TreeNode* sortedListToBST(ListNode* head) {
        return recurse(head);
    }
    
};