class Solution {
public:
    bool validMountainArray(vector<int>& inp) {
        bool increasingFound = false, decreasingFound = false;
        int size = inp.size();
        int i=0;
        while(i < size - 1 && inp[i] < inp[i+1]) {
            i++;
            increasingFound = true;
        }
        while(i < size - 1 && inp[i] > inp[i+1]) {
            i++;
            decreasingFound = true;
        }
        
        return increasingFound && decreasingFound && i == size-1;
    }
};