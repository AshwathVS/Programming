#include <iostream>

using namespace std;

void solve() {
	int n,k;
	cin >> n >> k;
	while(k > 0) {
		--k;
		if (n % 10 == 0) n /= 10;
		else n--;
	}
	cout << n << endl;
}

int main () {
	solve();
	return 0;
}
