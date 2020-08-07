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

Node *recurse(vector<int> &arr, int left, int right)
{
  if (left == right)
    return new Node(arr[left]);
  else
  {
    int mid = (left + right) / 2;
    Node *root = new Node(arr[mid]);
    root->left = recurse(arr, left, mid - 1);
    root->right = recurse(arr, mid + 1, right);
  }
}

Node *getTree(vector<int> &arr)
{
  return recurse(arr, 0, arr.size() - 1);
}

int main()
{
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << getTree(arr);
}
