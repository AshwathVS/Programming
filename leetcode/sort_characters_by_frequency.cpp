class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mm;
        for(char c : s) mm[c]++;

        sort(s.begin(), s.end(), [&](char a, char b) { return mm[a] != mm[b] ? mm[a] > mm[b] : a > b; });
        return s;
    }
};