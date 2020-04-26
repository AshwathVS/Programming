#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  long long n;
  bool found = false;
  cin >> n;
  long long f[50];
  f[0] = 0;
  f[1] = 1;

  for(int i=2; i<50; i++) {
    f[i] = f[i-1] + f[i-2];
  }

  for(int i=0; i<50; i++) {
    for(int j=i; j<50; j++) {
      for(int k=j; k<50; k++) {
        if (f[i]+f[j]+f[k]==n) {
          cout << f[i] << " " << f[j] << " " << f[k];
          found = true;
          goto out;
        }
      }
    }
  }

  out:
  if (!found) {
    cout << "I'm too stupid to solve this problem";
  }

}

int main() {
  solve();
  return 0;
}
