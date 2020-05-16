#include<bits/stdc++.h>

using namespace std;

void dfs_with_colored(int node, set<int> g[], bool visited[], int color[], int colorCnt) {
  if(visited[node]) return;
  else {
    visited[node]=true;
    color[node]=colorCnt;
    set<int> neighbors=g[node];
    for(auto it=neighbors.begin(); it!= neighbors.end(); it++) dfs_with_colored(*it, g, visited, color, colorCnt);
  }
}

void color_components(set<int> g[], bool visited[], int color[], int n) {
  int colorCnt=0;
  for(int i=1; i<n; i++) {
    if(!visited[i]) {
      colorCnt++;
      dfs_with_colored(i, g, visited, color, colorCnt);
    }
  }
}

int main() {
  int n, e;
  cin >> n;
  set<int> g[n+1];
  cin >> e;

  int ctr=0;
  for(int i=0; i<e; i++) {
    int a, b;
    cin >> a >> b;
    g[a].insert(b);
  }
  
  bool visited[n+1];
  int color[n+1];

  for(int i=1; i<n+1; i++) {
    visited[i]=false;
    color[i]=i;
  }


  color_components(g, visited, color, n); 
  
  cout << "Colors \n"; 
  for(int i=1; i<n+1; i++) {
    cout << i << " " << color[i] << "\n";
  }
}

