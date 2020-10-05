class MyCircularQueue {
private:
    int *arr;
    int size=0, max_size=0;
    int start=0, end=-1;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr = new int[k];
        max_size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()) {
            end++;
            end = end%max_size;

            arr[end] = value;
            size++;

            return true;
        } else return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()) {
            size--;
            start++;
            start = start % max_size;
            return true;
        } else return false;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        else return arr[start];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        else return arr[end];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == max_size;
    }
};