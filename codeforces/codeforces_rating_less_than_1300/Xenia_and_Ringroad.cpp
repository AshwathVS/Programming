#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int n, m;
  ll tot=0;
  cin >> n >> m;
  vector<int> v;
  copy_n(istream_iterator<int>(cin), m, back_inserter(v));
  int start=1;
  for(int i=0; i<m; i++) {
    if(v[i] == start) continue;
    if(v[i]>start) tot += (v[i]-start);
    else {
      tot += (n-start + v[i]);
    }
    start=v[i];
  }
  cout << tot << endl;
}

int main() {
  solve();
  return 0;
}
