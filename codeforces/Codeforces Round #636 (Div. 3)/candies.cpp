#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int t;
  cin >> t;
  vector<long long> out;
  while (t--) {
    long long n;
    cin >> n;
    long long k = 2;
    while(true) {
      int val = (k << 1) - 1;
      if (n % val == 0) {
        out.push_back(n/val);
        break;
      }
      k = (k << 1);
    }
  }

  for (auto it : out) {
    cout << it << endl;
  }
}

int main() {
  solve();
  return 0;
}
