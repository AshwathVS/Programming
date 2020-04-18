#include <iostream>

using namespace std;

int main() {
    int x;

    cin >> x;

    int ths = 0;
    int fvs = 0;
    if (x >= 500) {
        ths += (x / 500);
        x -= (ths * 500);
    }

    if (x >= 5) {
        fvs += (x / 5);
    }

    cout << ((ths * 1000) + (fvs * 5)) << endl;
}
