class MyStack {
public:
    queue<int> q1, q2;
    bool useOne = true;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if(useOne) q1.push(x);
        else q2.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int reverse(bool pop) {
        queue<int>* master, *slave;
        if(useOne) {
            master=&q1;
            slave=&q2;
        } else {
            master=&q2;
            slave=&q1;
        }

        useOne = !useOne;

        while(master->size() > 1) {
            slave->push(master->front());
            master->pop();
        }
        int res = master->front();
        master->pop();
        if(!pop) {
            slave->push(res);
        }

        return res;
    }

    int pop() {
        return reverse(true);
    }

    /** Get the top element. */
    int top() {
        return reverse(false);
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if(useOne) return q1.empty();
        else return q2.empty();
    }
};