#include <bits/stdc++.h>

using namespace std;

int maxDistanceInArrays(vector<vector<int>> inp) {
    int min1 = INT_MAX, min2 = INT_MAX, max = INT_MIN;
    int row_min1, row_min2, row_max;

    for(int i=0; i<inp.size(); i++) {
        if(inp[i][0] < min1) {
            min2 = min1;
            row_min2 = row_min1;
            min1 = inp[i][0];
            row_min1 = i;
        }

        if(inp[i][inp[i].size() - 1] > max) {
            max = inp[i][inp[i].size() - 1];
            row_max = i;
        }
    }

    if(row_max == row_min1) return max - min2;
    else return max - min1;
}

int main() {
    cout << maxDistanceInArrays({{1, 2, 3}, {4, 5}, {1, 2, 3}});
}
