
#include<bits/stdc++.h>

using namespace std;

void dfs(int node, set<int> g[], bool visited[], queue<int> &visitedNodes) {
    if(!visited[node]) {
        visited[node]=true;
        set<int> neighbors=g[node];

        for(auto it=neighbors.begin(); it!=neighbors.end(); it++) {
            dfs(*it, g, visited, visitedNodes);
        }
        visitedNodes.push(node);
    }
}

vector<int> topSort(set<int> g[], int n) {
    bool visited[n+1];
    for(int i=1; i<=n; i++) visited[i]=false;

    vector<int> order;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            queue<int> visitedNodes;
            dfs(i, g, visited, visitedNodes);

            while(!visitedNodes.empty()) {
                order.insert(order.begin(), visitedNodes.front());
                visitedNodes.pop();
            }
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
    for(auto i:order) cout << i << " ";
}


