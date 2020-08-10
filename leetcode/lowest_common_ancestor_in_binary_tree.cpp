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
        map<TreeNode*, TreeNode*> nodeRoot;
        dfs(root, p, q, NULL, nodeRoot);
        int p_length = 0;
        int q_length = 0;
        TreeNode* tmp = p;
        while(tmp != NULL) {
            tmp = nodeRoot[tmp];
            p_length++;
        }

        tmp = q;
        while(tmp != NULL) {
            tmp = nodeRoot[tmp];
            q_length++;
        }

        if(p_length != q_length) {
            if(p_length > q_length) {
                while(p_length > q_length) {
                    p = nodeRoot[p];
                    p_length--;
                }
            } else {
                while(p_length < q_length) {
                    q = nodeRoot[q];
                    q_length--;
                }
            }
        }

        while(p != q) {
            p = nodeRoot[p];
            q = nodeRoot[q];
        }

        return p;
    }

    void dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* root, map<TreeNode*, TreeNode*>& nodeRoot) {
        if(node == NULL) return;

        nodeRoot.insert({node, root});

        if(node == p) nodeRoot.insert({p, root});
        if(node == q) nodeRoot.insert({q, root});

        if(nodeRoot.find(p) == nodeRoot.end() || nodeRoot.find(q) == nodeRoot.end()) {
            dfs(node->left, p, q, node, nodeRoot);
        }

        if(nodeRoot.find(p) == nodeRoot.end() || nodeRoot.find(q) == nodeRoot.end()) {
            dfs(node->right, p, q, node, nodeRoot);
        }
    }
};

int main() {
    Solution s;
    TreeNode* seven = new TreeNode(7);
    TreeNode* zero = new TreeNode(0);
    TreeNode* root = new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2,  seven, new TreeNode(4))), new TreeNode(1, zero, new TreeNode(8)));
    s.lowestCommonAncestor(root, seven, zero);
}