#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    string inp;
    getline(cin, inp);
    stringstream s;
    s.str(inp);
    vector<int> vect;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        s >> tmp;
        total += tmp;
        vect.push_back(tmp);
    }
    int selectvote = (total / (4 * m));
    bool checkNext = (total % (4 * m) == 0);
    int ctr = 0;
    for (int i = 0; i < n; i++) {
        if (!checkNext && vect[i] > selectvote) ctr++;
        if (checkNext && vect[i] >= selectvote) ctr++;
    }
    if (ctr >= m) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
