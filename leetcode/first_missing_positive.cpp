class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        sort(A.begin(), A.end());
        int min = 1;
        for(int i : A) {
            if(min == i) min++;
            else if(min < i) break;
        }

        return min;
    }
};