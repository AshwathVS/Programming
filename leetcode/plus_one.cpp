class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1;
        for(int j = digits.size() - 1; j >= 0; j--) {
            int curr = rem + digits[j];
            digits[j] = curr % 10;
            rem = curr / 10;
        }
        if (rem > 0) {
            vector<int> :: iterator it = digits.begin();
            digits.insert(it, rem);
        }
        return digits;
    }
};