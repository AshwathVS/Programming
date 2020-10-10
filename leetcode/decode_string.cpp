class Solution {
public:
    string decodeString(string s) {
        stack<string> ss;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ']') {
                string curr = "";
                string decodedString = "";
                while(ss.top() != "[") {
                    curr = ss.top() + curr;
                    ss.pop();
                }
                ss.pop();
                int times = stoi(ss.top());
                ss.pop();
                for(int i=0; i<times; i++) {
                    decodedString += curr;
                }
                ss.push(decodedString);
            } else {
                if(isdigit(s[i])) {
                    int res = 0;
                    while(isdigit(s[i])) {
                        res = res*10 + (s[i] - '0');
                        i++;
                    }
                    ss.push(to_string(res));
                    i--;
                } else {
                    ss.push(string(1, s[i]));
                }
            }
        }

        string res = "";
        while(!ss.empty()) {
            res = ss.top() + res;
            ss.pop();
        }

        return res;
    }
};