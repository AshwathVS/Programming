class Solution {
public:
    vector<vector<vector<string>> > store;
    int size;

    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;j--;
        }

        return true;
    }

    vector<vector<string>> recurse(string s, int index) {
        if(index >= size) return {{}};
        if(!store[index].empty()) return store[index];

        int cnt = 1;
        vector<vector<string>> res;
        while(cnt <= size-index) {
            string str = s.substr(index, cnt);
            if(isPalindrome(str)) {
                vector<vector<string>> inter = recurse(s, index + cnt);
                for(vector<string> v : inter) {
                    vector<string> act;
                    act.push_back(str);
                    act.insert(act.end(), v.begin(), v.end());
                    res.push_back(act);
                }
            }
            cnt++;
        }

        store[index] = res;
        return res;
    }

    vector<vector<string>> partition(string s) {
        size = s.size();
        store = vector<vector<vector<string>> > (size);
        if(size == 0) return {};
        else if (size == 1) return {{s}};
        else return recurse(s, 0);
    }
};