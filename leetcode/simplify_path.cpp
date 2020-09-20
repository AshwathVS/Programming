class Solution {
public:
    void operate(stack<string>& ss, string folder) {
        if(folder == "" || folder == ".") return;

        if (folder == "..") {
            if(!ss.empty()) ss.pop();
        } else {
            ss.push(folder);
        }
    }

    string simplifyPath(string path) {
        stack<string> ss;
        int prevslash=0, size=path.size();

        for(int i=1; i<size; i++) {
            if(path[i] == '/') {
                if(i-1 != prevslash) {
                    int tt = prevslash+1;
                    string folder = path.substr(tt, i-tt);
                    operate(ss, folder);
                }
                prevslash = i;
            }
        }

        if(path.back() != '/') {
            string folder = path.substr(prevslash+1);
            operate(ss, folder);
        }

        if(ss.empty()) return "/";
        else {
            string res = "";

            while (!ss.empty()) {
                res = "/" + ss.top() + res;
                ss.pop();
            }

            return res;
        }
    }
};