#include <iostream>

using namespace std;

void solve() {
	int n,bills = 0,k;
	cin >> n;
	
	 k = (n / 100);
	 bills += k;
	 n -= (k * 100);
	 
	 k = (n / 20);
	 bills += k;
	 n -= (k * 20);
	 
	 k = (n / 10);
	 bills += k;
	 n -= (k * 10);
	 
	 k = (n / 5);
	 bills += k;
	 n -= (k * 5);
	 
	 k = (n / 1);
	 bills += k;
	 n -= (k * 1);
	 
	 cout << bills << endl;
}

int main () {
	solve();
}
