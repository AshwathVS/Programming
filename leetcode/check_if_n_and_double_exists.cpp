class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> ss;
        for(int i : arr) ss[i]++;

        for(pair<int, int> x : ss) {
            int i=x.first;
            int twice=i*2;
            if(ss.find(twice) != ss.end()) {
                if(i == twice) {
                    if(ss[i] > 1) return true;
                } else return true;
            }
        }
        
        return false;
    }
};