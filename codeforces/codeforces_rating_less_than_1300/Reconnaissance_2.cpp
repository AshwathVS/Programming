#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  vector<pair<int, int>> v;
  int n, tmp;
  cin >> n;
  cin.ignore();
  string s;
  getline(cin, s);
  istringstream iss(s);
  for (int i=0; i<n; i++) {
    iss >> tmp;
    v.push_back(make_pair(tmp, i));
  }
  sort(v.begin(), v.end());

  for(int i=0; i<n; i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }

  int diff=INT_MAX, first=0, end=0;
  for(int i=1; i<n; i++) {
    if (v[i].first - v[i-1].first < diff) {
      diff = v[i].first - v[i-1].first;
      first = v[i].second;
      end = v[i-1].second;
    }
  }
  cout << first + 1 << " " << end + 1 << endl;
}

int main() {
  solve();
  return 0;
}
