#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int n, sum=0, ctr=0;
  cin >> n;
  vector<int> v;
  v.reserve(n);
  copy_n(istream_iterator<int>(cin), n, back_inserter(v));
  for (int i = 0; i < n; i++) sum += v[i];
  n++;
  int pos = sum % n;
  for (int i=1; i<=5; i++) {
    if ((pos + i) % n != 1) ctr++;
  }
  cout << ctr;
}

int main() {
  solve();
  return 0;
}
