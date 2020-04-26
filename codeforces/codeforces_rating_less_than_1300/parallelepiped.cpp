#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  long long x, y, z;
  cin >> x >> y >> z;

  long long a, b, c;
  a = sqrt((z*x)/y);
  b = x/a;
  c = y/b;

  cout << 4*(a+b+c);

}

int main() {
  solve();
  return 0;
}
