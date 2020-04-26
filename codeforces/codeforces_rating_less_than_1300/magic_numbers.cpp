#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

// 114114
bool magicnumber(ll n) {
    string in=to_string(n);
    int i=0;
    while(i<in.length()) {
        if(in[i]=='1') {
            if(i+1<n && in[i+1]=='4') {
                if(i+2<n && in[i+2]=='4') i=i+3;
                else i=i+2;
            } else i++;
        } else return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    if(magicnumber(n)) cout << "YES";
    else cout << "NO";
}

int main() {
    solve();
    return 0;
}
