#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, ctr=0;
    cin >> n >> k;
    vector<int> in;
    in.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(in));
    int max=INT_MIN;
    long long sum=0;
    for(int i=0; i<n/2; i++) {
      int j=in[i] + in[n-1-i];
      sum += j;
      if (j > max) {
        max=j;
      }
    }
    long long avg = sum / (n/2);
    if (in.size() > 4) max = avg;


    for (int i=0; i<n/2; i++) {
      int j = in[i]+in[n-1-i];
      if (j!=max) ctr++;
    }
    cout << ctr << endl;
  }

}

int main() {
  solve();
  return 0;
}
