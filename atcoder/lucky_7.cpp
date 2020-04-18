#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;
  bool contains = false;
  while (a > 0) {
    int tmp = a % 10;
    if (tmp == 7) {contains = true; break;}
    a = a/ 10;
  }
  if (contains) cout << "Yes";
  else cout << "No";
}
