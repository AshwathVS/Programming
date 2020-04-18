#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    string tmp;
    getline(cin, tmp);
    stringstream ss(tmp);

    int perimeter, n;
    ss >> perimeter;
    ss.ignore(1);
    ss >> n;

    getline(cin, tmp);
    ss.clear();
    ss.str(tmp);

    set<int> inp;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        ss >> tmp;
        ss.ignore(1);
        inp.insert(tmp);
    }

    int max_diff = 0, start_point = -1, left = -1;
    for (int i = 0; i < perimeter; i++)
    {
        if (inp.find(i) != inp.end())
        {
            if (start_point == -1) {
                start_point = i;
            }

            if (left == -1) {
                left = i;
            }
            else {
                if ((i - left) > max_diff) {
                    max_diff = (i - left);
                }
                left = i;
            }
        }
    }

    int tm = (perimeter - left) + (start_point);
    if (tm > max_diff) {
        max_diff = tm;
    }
    cout << perimeter - max_diff << endl;
}
