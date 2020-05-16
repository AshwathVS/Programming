#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, e;
  cin >> n >> e;
  set<int> g[n+1];
  for(int i=0; i<e; i++) {
    int a, b;
    cin >> a >> b;
    g[a].insert(b);
  }

  queue<int> nodesToVisit;
  bool visited[n+1];
  for(int i=1; i<n+1; i++) visited[i] = false;

  // starting traversal from 1
  nodesToVisit.push(1);

  while(!nodesToVisit.empty()) {
    int i=nodesToVisit.front();
    nodesToVisit.pop();

    if(!visited[i]) {
      visited[i]=true;
      set<int> neighbors=g[i];
      for(auto it=neighbors.begin(); it!= neighbors.end(); it++) {
        if(!visited[*it]) nodesToVisit.push(*it);
      }
    }
  }

  for(int i=1; i<=n; i++)
    cout << visited[i] << "\n";
}

