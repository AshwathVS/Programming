#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        stack<pair<TreeNode*, int>> s;
        bool p_found = false;
        bool q_found = false;

        TreeNode* node = root;
        s.push({node, 0});
        while(!p_found || !q_found) {
            pair<TreeNode*, int> top = s.top();

            if(top.first == p) p_found = true;
            if(top.first == q) q_found = true;

            if(top.second == 2) {
                s.pop();
                if(ancestor == top.first) {
                    ancestor = s.top().first;
                }
            } else if(top.second == 1) {
                s.top().second++;
                if(top.first->right != NULL) {
                    if(!p_found && !q_found) {
                        ancestor = top.first->right;
                    }
                    s.push({top.first->right, 0});
                }
            } else {
                s.top().second++;
                if(top.first->left != NULL) {
                    if(!p_found && !q_found) {
                        ancestor = top.first->left;
                    }
                    s.push({top.first->left, 0});
                }
            }

        }

        return ancestor;
    }
};

int main() {
    Solution s;
    TreeNode* six = new TreeNode(6);
    TreeNode* seven = new TreeNode(7);
    TreeNode* four = new TreeNode(4);
    TreeNode* zero = new TreeNode(0);
    TreeNode* eight = new TreeNode(8);

    TreeNode* one = new TreeNode(1, zero, eight);
    TreeNode* two = new TreeNode(2, seven, four);
    TreeNode* five = new TreeNode(5, six, two);
    TreeNode* root = new TreeNode(3, five, one);

    TreeNode* test1 = new TreeNode(1, six, NULL);

    cout << s.lowestCommonAncestor(root, , six)->val;
}