#include <iostream>
using namespace std;
 
int main() {
  string a;
  cin >> a;
  
  if (a[2] == a[3] && a[4] == a[5]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
