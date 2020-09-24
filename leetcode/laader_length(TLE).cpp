bool isPossible(string& a, string &b) {
    int cnt=0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) {
            if(cnt == 1) return false;
            else cnt++;
        }
    }

    return true;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

    map<string, bool> visited;
    for(auto s : wordList) visited.insert({s, false});

    queue<pair<string, int>> ss;
    ss.push({endWord, 0});

    int res = INT_MAX;

    while(!ss.empty()) {
        auto top = ss.front();
        visited[top.first] = true;
        ss.pop();
        wordList.erase(remove(wordList.begin(), wordList.end(), top.first), wordList.end());
        for(string str : wordList) {
            if(isPossible(str, top.first)) {
                if(str == beginWord) {
                    cout << "A: " << str << " " << top.second << endl;
                    res = min (res, top.second+1);
                } else if(isPossible(str, beginWord)) {
                    cout << "B: " << str << " " << top.second << endl;
                    res = min (res, top.second+2);
                } else {
                    if(!visited[str]) {
                        ss.push({str, top.second+1});
                        visited[str] = true;
                    }
                }
            }
        }
    }

    return res == INT_MAX?0:res+1;
}
