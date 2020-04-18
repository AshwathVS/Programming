#include <iostream>

using namespace std;

int __gcd(int a, int b) { return b ? __gcd(b, a % b) : a; }

int getgcd(int a, int b, int c) {
    return __gcd(a, __gcd(b, c));
}

int main() {
    int k;
    cin >> k;
    long long res = 0;
    for (int a = 1; a <= k; a++) {
        for (int b = 1; b <= k; b++) {
            for (int c = 1; c <= k; c++) {
                res += getgcd(a, b, c);
            }
        }
    }
    cout << res << endl;
}
