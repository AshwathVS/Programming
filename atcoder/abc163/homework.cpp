const double PI = 3.14;

#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long d, a, tm;
  cin >> d >> a;
  for(int i=0; i<a; i++) {
    cin >> tm;
    if (d >= 0) d -= tm;
  }
  if (d < 0) cout << "-1";
  else cout << d;
}

int main () {
  solve();
  return 0;
}
