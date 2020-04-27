#include <bits/stdc++.h>

using namespace std;

#define pp pair<int, int>
#define ll long long
// copy_n(istream_iterator<int>(cin), n, back_inserter(s));

void solve() {
    ll n, tmp, i=0;
    cin >> n;
    cin.ignore();

    map<ll, vector<ll>> store;
    vector<pair<ll, ll>> res;
    string in;
    getline(cin, in);
    istringstream iss(in);
    for(i=0; i<n; i++) {
        iss>>tmp;
        if(store.find(tmp)==store.end()) {
            vector<ll> v;
            v.push_back(i);
            store[tmp]=v;
        } else {
            store[tmp].push_back(i);
        }
    }

    for(map<ll, vector<ll>>::iterator it=store.begin(); it!=store.end(); it++) {
        if(it->second.size()==1) res.push_back(make_pair(it->first, 0));
        else {
            vector<ll> indexes=it->second;
            ll diff=indexes[1]-indexes[0];
            bool valid=true;
            for(int i=1; i<indexes.size()-1; i++) {
                if(indexes[i]+diff != indexes[i+1]) valid=false;
            }
            if(valid) {
                res.push_back(make_pair(it->first, diff));
            }
        }
    }


    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
}

int main() {
    solve();
    return 0;
}
