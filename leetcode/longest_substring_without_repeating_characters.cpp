class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> seen;
        int maxx = INT_MIN, count = 0, start = 0;

        for(int i=0; i<s.size(); i++) {
            char c = s[i];

            if(seen.find(c) != seen.end()) {
                while(s[start] != c) {
                    seen.erase(s[start]);
                    start++;
                    count--;
                }
                start++;
            } else {
                seen.insert(c);
                count++;
                maxx = max(maxx, count);
            }
        }

        return maxx == INT_MIN? 0 : maxx;
    }
};
