#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,sum = 0,k;
	cin >> n;
	
	k = n/5;
	sum += k;
	n -= (k * 5);
	
	k = n/4;
	sum += k;
	n -= (k * 4);
	
	k = n/3;
	sum += k;
	n -= (k * 3);
	
	k = n/2;
	sum += k;
	n -= (k * 2);
	
	k = n/1;
	sum += k;
	n -= (k * 1);
	
	cout << sum << endl;
}
	

int main () {
	solve();
	return 0;
}
