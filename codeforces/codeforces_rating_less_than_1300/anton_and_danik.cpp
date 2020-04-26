#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n,an = 0, dan=0;
	string in;
	cin >> n;
	cin.ignore(1);
	cin >> in;
	for (int i = 0; i < n; i++) {
		if (in[i] == 'A') an++;
		else dan++;
	}
	
	if (an > dan) cout << "Anton";
	else if (an == dan) cout << "Friendship";
	else cout << "Danik";
}

int main () {
	solve();
} 
