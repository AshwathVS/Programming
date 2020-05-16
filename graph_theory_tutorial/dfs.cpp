#include <bits/stdc++.h>

using namespace std;

void dfs(int node, set<int> g[], bool visited[]) {
 if(visited[node]) return;
 else {
    visited[node]=true;
    set<int> neighbors=g[node];
    
    for(auto it=neighbors.begin(); it!=neighbors.end(); it++) {
      dfs(*it, g, visited);
    }
 }
}


int main() {
  int n, e;
  
  cin >> n;
  set<int> g[n + 1];
  
  cin >> e;
  for(int i=0; i<e; i++) {
    int a, b;
    cin >> a >> b;
    g[a].insert(b);
  }

  bool visited[n+1];
  for(int i=0; i<n+1; i++) visited[i]=false;

  dfs(1, g, visited);
  for(int i=0; i<n+1; i++) cout << visited[i];
}
