#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  reverse(s1.begin(), s1.end());
  if(s1 == s2) cout << "YES";
  else cout << "NO";
}

int main() {
  solve();
  return 0;
}
