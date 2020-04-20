#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int n;
  cin >> n;
  vector<int> s;
  s.reserve(7);
  copy_n(istream_iterator<int>(cin), 7, back_inserter(s));

  int i = 0;
  int lastread = i;
  while(n > 0) {
    if (i == 7) i = 0;

    if (s[i] > 0) {
      n -= s[i];
      lastread = i;
    }
    i++;
  }

  cout << lastread + 1 << endl;
}

int main() {
  solve();
  return 0;
}
