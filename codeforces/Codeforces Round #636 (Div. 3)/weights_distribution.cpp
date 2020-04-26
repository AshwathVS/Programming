#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

/*
Solution Not accepted!!
*/
vector<ll> path(vector<vector<ll>> g, ll a, ll b) {
    queue<ll> q;
    vector<ll> pred(g.size()+1, -1);
    bool vis[g.size()+1];
    for(int i=0; i<g.size()+1; i++) vis[i] = false;
    vis[a]=true;
    q.push(a);
    pred[a]=a;
    vector<ll> res;
    while(true && !q.empty()) {
        ll t=q.front();
        q.pop();
        if(t == b) break;
        vector<ll> neighbors=g[t];

        for(int i=0; i<neighbors.size(); i++) {
            if(neighbors[i] == 1 && !vis[i]) {
                q.push(i);
                vis[i]=true;
                pred[i]=t;
                if (i == b) goto found;
            }
        }
    }
    found:
    ll node=b;
    while(pred[node]!=node) {
        res.insert(res.begin(), node);
        node=pred[node];
    }
    res.insert(res.begin(), node);
    return res;
}

vector<ll> getPath(vector<vector<ll>> g, ll a, ll b, ll c) {
    vector<ll> aTob = path(g, a, b);
    vector<ll> bToc = path(g, b, c);
    map<pair<ll, ll>, ll> freq;
    for(int i=0; i<aTob.size()-1; i++) {
        freq[make_pair(min(aTob[i], aTob[i+1]), max(aTob[i], aTob[i+1]))]++;
    }
    for(int i=0; i<bToc.size()-1; i++) {
        freq[make_pair(min(bToc[i], bToc[i+1]), max(bToc[i], bToc[i+1]))]++;
    }
    vector<ll> ret;
    for(map<pair<ll, ll>, ll>::iterator it=freq.begin(); it!=freq.end(); it++) {
        ret.push_back(it->second);
    }
    sort(ret.begin(), ret.end(), greater<int>());
    return ret;
}

void solve() {
    int test;
    cin >> test;

    while(test--) {
        ll n, m, a, b, c, v1, v2;
        cin >> n >> m >> a >> b >> c;
        vector<ll> p;
        copy_n(istream_iterator<ll>(cin), m, back_inserter(p));
        vector<vector<ll>> g(n+1, vector<ll>(n+1, 0));
        for (ll i=0; i<m; i++) {
            cin >> v1 >> v2;
            g[v1][v2] = 1;
            g[v2][v1] = 1;
        }

        sort(p.begin(), p.end());
        ll tot=0, i=0;
        vector<ll> path = getPath(g, a, b, c);
        for(vector<ll>::iterator it=path.begin(); it!=path.end(); it++) {
          // cout << *it << " " << p[i] << endl;
          tot+=(*it * p[i]);
          i++;
        }
        cout << tot << endl;
    }
}

int main() {
    solve();
    return 0;
}
