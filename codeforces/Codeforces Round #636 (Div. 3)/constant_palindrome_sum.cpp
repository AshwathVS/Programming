#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int t;
  cin >> t;
  while (t--) {
      int n, k;
      cin >> n >> k;
      vector<int> a(n+4, 0), cnt((2*k) + 4, 0);
      // for (int i = 1; i < cnt.size(); i++)cnt[i] = 0;
      for (int i = 1; i <= n; i++)
          scanf("%d", &a[i]);

      for (int i = 1; i <= n / 2; i++) {
          cnt[1] += 2;
          cnt[min(a[i], a[n - i + 1]) + 1]--;
          cnt[max(a[i], a[n - i + 1]) + k + 1]++;
          cnt[a[i] + a[n - i + 1]]--;
          cnt[a[i] + a[n - i + 1] + 1]++;
      }
      int ans = n;
      for (int i = 1; i <= k * 2; i++) {
          cnt[i] += cnt[i - 1];
          ans = min(ans, cnt[i]);
      }
      cout << ans << endl;
  }
}

int main() {
  solve();
  return 0;
}
