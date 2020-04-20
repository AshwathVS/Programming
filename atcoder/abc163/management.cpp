#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    vector<int> in, c;
    in.reserve(n);
    c.reserve(n);
    for (int i = 0; i < n; i++)
      c[i] = 0;

    string r;
    getline(cin, r);
    istringstream iss(r);

    for(int i=0; i<n-1; i++) {
      iss >> in[i];
      c[in[i] - 1]++;
    }

    for(int i=0; i<n; i++) cout << c[i] << endl;

}

int main () {
    solve();
    return 0;
}
