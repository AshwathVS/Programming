#include <iostream>
using namespace std;


char getThird(char a, char b) {
    return ('R' + 'G' + 'B' - (a + b));
}

long long rgb(string inp) {
    const int len = inp.length();
  	if (len <= 3) return 0;
    int* r_count = new int[len + 1];
    int* g_count = new int[len + 1];
    int* b_count = new int[len + 1];
    int* arrToUse = NULL;

    r_count[len] = 0;
    g_count[len] = 0;
    b_count[len] = 0;

    for (int i = inp.length() - 1; i >= 0; i--) {
        r_count[i] = r_count[i + 1];
        g_count[i] = g_count[i + 1];
        b_count[i] = b_count[i + 1];

        if (inp[i] == 'R') r_count[i]++;
        if (inp[i] == 'G') g_count[i]++;
        if (inp[i] == 'B') b_count[i]++;
    }
    long long ret = 0;
    
    for (int i = 0; i < inp.length() - 2; i++) {
        for (int j = i + 1; j < inp.length() - 1; j++) {
            if (inp[j] != inp[i]) {
                char third = getThird(inp[i], inp[j]);
                if (third == 'R') arrToUse = r_count;
                else if (third == 'G') arrToUse = g_count;
                else arrToUse = b_count;
                
                int val = arrToUse[j + 1];
                if (val > 0 && (j + (j - i) < inp.length()) && inp[j + (j - i)] == third) {
                    val--;
                }
                ret += val;
            }
        }
    }

    arrToUse = NULL;

    delete[] r_count;
    delete[] g_count;
    delete[] b_count;

    return ret;
}

int main() {
  int n;
  string inp;
  cin >> n;
  cin >> inp;
  cout << rgb(inp) << endl;
}
