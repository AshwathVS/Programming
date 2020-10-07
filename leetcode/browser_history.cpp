class BrowserHistory {
    vector<string> history;
    int end=0, curr=-1;
public:
    BrowserHistory(string homepage) {
        history = vector<string>(5000);
        visit(homepage);
    }

    void visit(string url) {
        history[++curr] = url;
        end = curr;
    }

    string back(int steps) {
        curr -= steps;
        if(curr < 0) curr = 0;
        return history[curr];
    }

    string forward(int steps) {
        curr += steps;
        if(curr > end) curr = end;
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */