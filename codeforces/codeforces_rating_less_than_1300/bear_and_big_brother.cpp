#include <iostream>

using namespace std;

void solve() {
	int l,b;
	cin >> l >> b;
	int ctr = 0;
	while (l <= b) {
		ctr++;
		l *= 3;
		b *= 2;
	}
	cout << ctr << endl;
}

int main () {
	solve();
}
