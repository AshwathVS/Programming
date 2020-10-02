/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> ss;

    void setNext(TreeNode* curr) {
        while(curr != NULL) {
            ss.push(curr);
            curr = curr->left;
        }
    }

public:

    BSTIterator(TreeNode* root) {
        setNext(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = ss.top();
        ss.pop();
        setNext(tmp->right);
        return tmp->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ss.size() > 0;
    }
};