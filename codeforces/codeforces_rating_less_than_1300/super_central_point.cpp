#include <bits/stdc++.h>

using namespace std;

void solve()
{
	vector<pair<int, int> > pts;
  int _n, _a, _b;
  cin >> _n;

  for (int i=0; i<_n; i++) {
    cin >> _a >> _b;
    pts.push_back(make_pair(_a, _b));
  }

	int ctr = 0;
	int l,r,u,d;
	for (int i=0; i<_n; i++) {
		l=r=u=d=0;
		for (int j=0; j<_n; j++) {
			if (i!=j) {
				if (pts[j].first == pts[i].first) {
					// up
					if (pts[j].second > pts[i].second) u++;
					// down
					if (pts[j].second < pts[i].second) d++;
				}

				if (pts[j].second == pts[i].second) {
					// left
					if (pts[j].first < pts[i].first) l++;
					// right
					if (pts[j].first > pts[i].first) r++;
				}
			}
		}
		if (l&&r&&u&&d) {
			ctr++;
			// cout << "Adding point: " << i << endl;
		}
	}

	cout << ctr << endl;

}

int main() {
  solve();
  return 0;
}

//
// 9
// 0 0
// 1 0
// 0 1
// -1 0
// 0 -1
// 1 1
// 1 -1
// -1 1
// -1 -1
