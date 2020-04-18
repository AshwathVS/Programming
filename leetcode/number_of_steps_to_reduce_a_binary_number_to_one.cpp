class Solution {
public:
    int numSteps(string s) {
    int steps = 0;

    vector<bool> convert;
    for (int i = 0; i < s.length(); i++) convert.push_back(s[i] - '0');

    while (convert.size() != 1) {
        int last = convert.back();
        if (last == 0) {
            convert.pop_back();
        }
        else {
            convert[convert.size() - 1] = 0;
            int rem = 1;
            int ind = convert.size() - 2;
            while (rem != 0 && ind >= 0) {
                if (convert[ind] == 1) convert[ind] = 0;
                else {
                    convert[ind] = 1;
                    rem = 0;
                }
                ind--;
            }
            if (rem == 1) convert.insert(convert.begin(), 0);
        }
        steps++;
    }
    return steps;
    }
};