class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> ss;

        for(int i=0; i<s.size(); i++) {
            if(!ss.empty() && ss.top().first == s[i]) ss.top().second++;
            else ss.push({s[i], 1});

            if(ss.top().second == k) ss.pop();
        }

        string res = "";
        while(!ss.empty()) {
            pair<char, int> top = ss.top();
            ss.pop();
            string tmp = "";
            for(int i=0; i<top.second; i++) tmp += top.first;
            res = tmp + res;
        }

        return res;
    }
};