#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  copy_n(istream_iterator<int>(cin), n, back_inserter(v));
  sort(v.begin(), v.end());
  int tot=0, i=0;
  while(m--) {
    if(tot-v[i] >= tot) tot-=v[i];
    i++;
  }
  cout << tot;
}

int main() {
  solve();
  return 0;
}
