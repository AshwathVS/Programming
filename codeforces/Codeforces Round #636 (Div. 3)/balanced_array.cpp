#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int nBy2 = n / 2;
    if (nBy2 % 2 != 0) {
      cout << "NO";
    } else {
      int j=2;
      cout << "YES" << endl;
      for (int i=0; i<nBy2; i++) {
        cout << j << " ";
        j+=2;
      }
      j-=2;

      int k=1;
      for (int i=0; i<nBy2-1; i++) {
        cout << k << " ";
        k+=2;
      }
      cout << k + nBy2;
    }
    cout << endl;

  }

}

int main() {
  solve();
  return 0;
}
