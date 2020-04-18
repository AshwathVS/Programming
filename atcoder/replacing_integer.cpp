#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (n < k) {
        if (n < abs(k - n)) cout << n << endl;
        else cout << abs(k - n) << endl;
    }
    else if (n == k) cout << 0 << endl;
    else {
        long long rem = n % k;
        if (rem == 0) cout << 0 << endl;
        else cout << k - rem << endl;
    }
    return 0;
}
