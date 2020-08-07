#include <bits/stdc++.h>

using namespace std;

int main()
{
  // directed graph
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

  int source = 0;
  int dest = 3;
  int nodeCount = 4;
  bool path = false;

  queue<int> q;
  vector<int> visited(nodeCount);

  q.push(source);

  while (!q.empty())
  {
    int node = q.front();
    visited[node] = true;
    q.pop();
    if (node == dest)
    {
      path = true;
      break;
    }
    else
    {
      for (int neighbor : graph[node])
      {
        if (!visited[neighbor])
          q.push(neighbor);
      }
    }
  }

  if (path)
    cout << "Path exists";
  else
    cout << "No path found";
}
