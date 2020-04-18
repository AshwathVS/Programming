#include <iostream>

using namespace std;

void solve() {
	int n,k;
	cin >> n;
	while (n--) {
		cin >> k;
		if (k == 1) { 
			cout << "HARD" << endl;
			return;
		}
	}
	cout << "EASY" << endl;

}

int main () {
	solve();
	return 0;
}

