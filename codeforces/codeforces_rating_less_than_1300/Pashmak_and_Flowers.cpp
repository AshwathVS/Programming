#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int n;
  vector<ll> v;
  copy_n(istream_iterator<ll>(cin), n, back_inserter(v));
  sort(v.begin(), v.end());
  int lc=1, rc=1, i=0, c=0;
  
  cout << v[v.size()-1] - v[0] << " " << c;

}

int main() {
  solve();
  return 0;
}
