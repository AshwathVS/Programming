class CustomStack {
public:
    stack<int> ss;
    vector<int> inc;
    int maxSize;

    CustomStack(int maxSize) {
        inc = vector<int>(maxSize, 0);
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(ss.size() < maxSize) {
            ss.push(x);
        }
    }

    int pop() {
        if(!ss.empty()) {
            int res = ss.top() + inc[ss.size()-1];
            inc[ss.size()-1] = 0;
            ss.pop();
            return res;
        } else return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<ss.size(); i++) {
            inc[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */