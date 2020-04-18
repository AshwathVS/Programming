#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n <= 12) cout << n;
    else {
        //n -= 9;
        queue<long long> nums;
        for (int i = 0; i < 10; i++) nums.push(i);

        while (n > 0) {
            n--;
            long long front = nums.front();
            nums.pop();
            if (front == 0) continue;
            int ones = front % 10;
            front *= 10;
            if (ones - 1 >= 0) nums.push(front + (ones - 1));
            nums.push(front + ones);
            if (ones + 1 < 10) nums.push(front + (ones + 1));
        }
        cout << nums.front() << endl;
    }
}
