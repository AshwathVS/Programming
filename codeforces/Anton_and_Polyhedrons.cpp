#include <iostream>

using namespace std;

void solve() {
	int n,sum = 0;
	cin >> n;
	while (n--) {
		string in;
		cin >> in;
		if (in == "Tetrahedron") sum += 4;
		if (in == "Cube") sum += 6;
		if (in == "Octahedron") sum += 8;
		if (in == "Dodecahedron") sum += 12;
		if (in == "Icosahedron") sum += 20;
	}
	cout << sum << endl;
}

int main () {
	solve();
}
