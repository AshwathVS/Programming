#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
  ll n;
  cin >> n;
  vector<ll> v;
  copy_n(istream_iterator<ll>(cin), n, back_inserter(v));
  sort(v.begin(), v.end());
  ll lc=1, rc=1, i=0;
  ll c=0;
  while(i<v.size()-1 && v[i]==v[i+1]) {
    i++;
    lc++;
  }
  if(i==n-1) {
    if(n==2) c=1;
    else c=n*(n-1)/2;
  }
  else {
    i=v.size()-1;
    while(i>=1 && v[i]==v[i-1]) {
      i--;
      rc++;
    }
    c=lc*rc;
  }
  cout << v[v.size()-1] - v[0] << " " << c;

}

int main() {
  solve();
  return 0;
}
