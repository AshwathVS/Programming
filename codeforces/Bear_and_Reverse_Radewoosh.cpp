#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, p, l=0, r=0, l1=0, r1=0;
    cin >> n >> p;
    vector<int> s,t;
    s.reserve(n);
    t.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(s));
    copy_n(istream_iterator<int>(cin), n, back_inserter(t));

    for(int i=0; i<n; ++i) {
        int score = (s[i] - (p * (t[i] + l1)));
        if(score > 0) l += score;
        l1 += t[i];
    }

    for(int i=n-1; i>=0; --i) {
        int score = (s[i] - (p * (t[i] + r1)));
        if(score > 0) r += score;
        r1 += t[i];
    }

    if (l > r) cout << "Limak";
    else if (l == r) cout << "Tie";
    else cout << "Radewoosh";
}

int main () {
    solve();
}
