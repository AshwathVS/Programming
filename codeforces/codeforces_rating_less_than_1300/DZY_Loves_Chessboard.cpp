#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

char getChar(bool white) {
  if(white) return 'W';
  else return 'B';
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> v;

  for(int i=0; i<n; i++) {
    vector<char> in;
    copy_n(istream_iterator<char>(cin), m, back_inserter(in));
    v.push_back(in);
  }
  bool white=false;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if (v[i][j]=='.') cout << getChar(white);
      else cout << v[i][j];
      white=!white;
    }
    if(m%2 == 0) {
      white=!white;
    }
    cout << endl;
  }
}

int main() {
  solve();
  return 0;
}
