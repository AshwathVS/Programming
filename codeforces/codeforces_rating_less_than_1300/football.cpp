#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  int n;
  cin >> n;
  cin.ignore();
  string t1="", t2="", inp="";
  int _t1=0, _t2=0;
  while(n--) {
    getline(cin, inp);
    if (inp==t1) {
      _t1++;
    } else if(inp==t2) {
      _t2++;
    } else {
      if(t1=="") {
        t1=inp;
        _t1++;
      } else {
        t2=inp;
        _t2++;
      }
    }
  }

  if (_t1>_t2) cout << t1;
  else cout << t2;
}

int main() {
  solve();
  return 0;
}
