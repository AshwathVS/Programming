class MyCircularDeque {
private:
    int *arr;
    int start=0, end=-1;
    int size=0, max_size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        arr = new int[k];
        max_size = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(!isFull()) {
            start--;
            if(start < 0) start = max_size-1;
            arr[start] = value;
            size++;
            if(size == 1) end = start;
            return true;
        }

        return false;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(!isFull()) {
            end++;
            end=end%max_size;
            arr[end] = value;
            size++;
            if(size == 1) start = end;
            return true;
        }

        return false;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(!isEmpty()) {
            size--;
            start++;
            start = start%max_size;
            return true;
        }

        return false;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(!isEmpty()) {
            size--;
            end--;
            if(end < 0) end = max_size-1;
            return true;
        }

        return false;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(!isEmpty()) {
            return arr[start];
        }

        return -1;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(!isEmpty()) {
            return arr[end];
        }

        return -1;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == max_size;
    }
};