#include<bits/stdc++.h>

using namespace std;

int path(int** g, int n, int start, int end) {
  int dist[n];
  for(int i=0; i<n; i++) {
    if(i==start) dist[i]=0;
    else dist[i]=INT_MAX;
  }

  // dist, node pair
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));

  while(!pq.empty()) {
    auto node=pq.top();
    pq.pop();

    int parent=node.second;
    
    if(dist[parent]<node.first) continue;

    for(int i=0; i<n; i++) {
      if(g[parent][i]!=INT_MAX) {
        if(node.first+g[parent][i] < dist[i]) {
          dist[i]=node.first+g[parent][i];
          pq.push(make_pair(dist[i], i));
        }
      } 
    }
  }

  return dist[end];
}

int main() {
  int n, m;
  cin >> n >> m;

  int** g;
  g=new int*[n];

  for(int i=0; i<n; i++) {
    g[i]=new int[n];
    for(int j=0; j<n; j++) {
      if(i==j) g[i][j]=0;
      else g[i][j]=INT_MAX;
    }
  }

  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a][b]=c;
  }

  int dist=path(g, n, 0, 1);
  cout << dist << endl;
}
