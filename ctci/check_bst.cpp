#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    Node(int val, Node *left, Node *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

bool isBst(Node *node)
{
    if (node == NULL)
        return true;
    else
    {
        bool isBstForNode = true;
        if (node->left != NULL)
            isBstForNode = node->val > node->left->val;
        if (node->right != NULL)
            isBstForNode = isBstForNode && node->val < node->right->val;

        return isBst(node->left) && isBst(node->right) && isBstForNode;
    }
}

int main()
{
    Node *root = new Node(4, new Node(2, new Node(1), new Node(3)), new Node(6, new Node(5), new Node(7)));
    cout << isBst(root);
}
