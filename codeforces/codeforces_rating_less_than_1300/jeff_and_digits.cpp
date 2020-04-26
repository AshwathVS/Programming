#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  copy_n(istream_iterator<int>(cin), n, back_inserter(v));
  int cnt_5=0, cnt_0=0;
  for(int i=0; i<n; i++) {
    if (v[i] == 5) cnt_5++;
    else cnt_0++;
  }

  cnt_5-=(cnt_5%9);
  if(cnt_5 && cnt_0) {
    while(cnt_5--) cout << 5;
    while(cnt_0--) cout << 0;
  } else if(cnt_0) {
    cout << 0;
  } else cout << -1;
}

int main() {
  solve();
  return 0;
}
