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
    vector<long long> in;
    vector<long long> out;
    in.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(in));
    int i=0, ind=0, j;
    long long sum=0, max=0;
    while(i<n) {
      // find max signed number
      if (in[i] >= 0) {
        max=in[i], j=i;
        while(in[j] >= 0 && j<n) {
          if (in[j] > max) max = in[j];
          j++;
        }
      } else {
        max=in[i], j=i;
        while(in[j] < 0 && j<n) {
          if (in[j] > max) max = in[j];
          j++;
        }
      }
      i=j;
      sum += max;
    }
    cout << sum << endl;
  }

}

int main() {
  solve();
  return 0;
}
