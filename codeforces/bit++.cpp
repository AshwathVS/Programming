#include <bits/stdc++.h>

using namespace std;

//https://codeforces.com/problemset/problem/282/A

void solve() {
  int t, base = 0;
  cin >> t;
  cin.ignore();
  string inp;
  while(t--) {
    getline(cin, inp);
    if (inp.find("--") != string::npos) --base;
    else if (inp.find("++") != string::npos) ++base;
  }

  cout << base << endl;
}

int main() {
  solve();
  return 0;
}
