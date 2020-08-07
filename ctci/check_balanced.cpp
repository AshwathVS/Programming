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

int depth(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        return 1 + max(depth(node->left), depth(node->right));
    }
}

int isBalanced(Node *node)
{
    return abs(depth(node->left) - depth(node->right)) <= 1;
}

int main()
{
    Node *root = new Node(4, new Node(2, new Node(1), new Node(3)), new Node(6, new Node(5), new Node(7)));
    cout << isBalanced(root);
}
