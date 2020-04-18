#include<bits/stdc++.h>

using namespace std;

int p[2][101];

void solve() {
	int n;
	cin >> n;
	cin.ignore(1);
	string s;
	getline(cin, s);
	istringstream iss(s);
	
	for (int i = 1; i <= n; i++) {
		iss >> p[0][i];
		p[1][p[0][i]] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << p[1][i] << " "; 
	
}
int main () {
	solve();
} 
