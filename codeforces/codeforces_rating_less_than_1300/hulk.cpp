#include <iostream>

using namespace std;

void solve() {
	int n,k = 1;
	cin >> n;
	while (k <= n) {
		if (k % 2 != 0) cout << "I hate ";
		else cout << "I love ";
		
		if (k == n) cout << "it";
		else cout << "that ";
		k++;
	}
}

int main () {
	solve();
}

