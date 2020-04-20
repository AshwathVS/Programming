#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
    int n, m, ind=-1, iter=-1, t2, diff;
    cin >> n >> m;
    vector<int> s;
    copy_n(istream_iterator<int>(cin), n, back_inserter(s));
    for(int i = 0; i < n; i++) {
        diff = s[i] / m;
        t2 = s[i] % m;
        if (t2>0) ++diff;

        if (diff >= iter && i > ind) {
            ind = i;
            iter = diff;
        }
    }
    cout << ind + 1;
}

int main() {
    solve();
    return 0;
}
