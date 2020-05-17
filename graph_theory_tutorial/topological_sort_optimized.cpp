#include<bits/stdc++.h>

using namespace std;

int dfs(int node, set<int> g[], bool visited[], vector<int> &visitedNodes, int i) {
    if(!visited[node]) {
        visited[node]=true;
        set<int> neighbors=g[node];

        for(auto it=neighbors.begin(); it!=neighbors.end(); it++) {
            i=dfs(*it, g, visited, visitedNodes, i);
        }
        visitedNodes[i]=node;
        return i-1;
    } else return i;
}

vector<int> topSort(set<int> g[], int n) {
    bool visited[n+1];
    for(int i=1; i<=n; i++) visited[i]=false;

    vector<int> order(n+1);
    int _i=n;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            _i=dfs(i, g, visited, order, _i);
        }
    }

    return order;
}

int main() {
    int n, e;
    cin >> n >> e;
    set<int> g[n+1];

    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
    }

    vector<int> order=topSort(g, n);
    for(int i=1; i<=n; i++) cout << order[i] << " ";
}

