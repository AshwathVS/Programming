#include <bits/stdc++.h>

using namespace std;

// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  long long n, t;
  set<long long> _s;
  vector<pair<int, int>> v;

  string s;
  cin >> n;
  cin.ignore();
  bool dup = false;

  getline(cin, s);
  v.reserve(n);
  istringstream iss(s);
  for (int i=1; i<=n; i++) {
    iss >> t;
    v.push_back(make_pair(t, i));
  }

  sort(v.begin(), v.end());
  if (v.size() > 1) {
    if (v[0].first == v[1].first) {
      cout << "Still Rozdil" << endl;
    } else {
      cout << v[0].second;
    }
  } else {
    cout << v[0].second;
  }
}

int main() {
  solve();
  return 0;
}
