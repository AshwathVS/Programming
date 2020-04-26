#include <bits/stdc++.h>

using namespace std;

// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  long long a, b, i;
  cin >> a >> b;
  long long on = (a/2);
  if (a%2 != 0) on++;

  if (b<=on) i=1;
  else {
    i=2;
    b-=on;
  }

  b--;

  while (b > 0) {
    i+=2;
    b--;
  }

  cout << i;
}

int main() {
  solve();
  return 0;
}
