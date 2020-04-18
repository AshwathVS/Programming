#include <iostream>

using namespace std;

int main () {
  int inp;
  cin >> inp;
  long long sum = 0;
  while (inp > 0) {
    if (inp % 3 != 0 && inp % 5 != 0) sum += inp;
    inp--;
  }
  cout << sum;
}
