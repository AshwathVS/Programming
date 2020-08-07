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

vector<vector<int>> levelOrders(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>> res;
    while (q.size() > 1)
    {
        vector<int> v;

        while (true)
        {
            Node *n = q.front();
            q.pop();
            if (n == NULL)
                break;
            else
            {
                v.push_back(n->val);
                if (n->left != NULL)
                    q.push(n->left);
                if (n->right != NULL)
                    q.push(n->right);
            }
        }

        q.push(NULL);
        res.push_back(v);
    }

    return res;
}

int main()
{
    /*
                4
            2       6
          1   3   5   7
    */
    Node *root = new Node(4, new Node(2, new Node(1), new Node(3)), new Node(6, new Node(5), new Node(7)));
    vector<vector<int>> lst = levelOrders(root);
    for (vector<int> i : lst)
    {
        for (int j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}
