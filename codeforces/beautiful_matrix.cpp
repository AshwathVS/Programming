#include <bits/stdc++.h>

using namespace std;

int arr[5][5];

void solve() {
	int out = 0;
	for (int i = 0; i < 5; i++)
		for(int j = 0; j <5; j++) {
			cin>> arr[i][j];
			if (arr[i][j] == 1)
				out = abs(2 - i) + abs(2 - j);
		}
	cout << out << endl;
}
	
int main () {
	solve();
}
