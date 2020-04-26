#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &l,const pair<int, int> &r) {
    return l.first < r.first;
}

void solve() {
    int n, m, tmp;
    long long  v=0, p=0;
    vector<pair<int, int>> in;
    vector<int> q;
    cin >> n;
    in.reserve(n);
    cin.ignore();
    string s;
    getline(cin, s);
    istringstream iss(s);
    for(int i = 0; i<n; i++) {
        iss >> tmp;
        in.push_back(make_pair(tmp, i));
    }
    cin >> m;
    q.reserve(m);
    copy_n(istream_iterator<int>(cin), m, back_inserter(q));

    sort(in.begin(), in.end());
    for (int i = 0; i < m; i++) {
        int find = q[i];
        int index = lower_bound(in.begin(), in.end(), make_pair(find, 0), cmp) - in.begin();
        if (index < in.size()) {
            v += in[index].second + 1;
            p += (in.size() - in[index].second);
        }
    }
    cout << v << " " << p << endl;
}

int main() {
    solve();
    return 0;
}
