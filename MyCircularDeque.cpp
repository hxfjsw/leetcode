//
// Created by lion on 2019-06-21.
//

#include <vector>
#include <iostream>

using namespace std;


class MyCircularDeque {
    vector<int> queue;
    int head = 0; // goes forward
    int tail = 0; // goes backward
    // +------+---+---+---+--+--+--+--+--+--+------+
    // |  0   | 1 | 2 | 3 |  |  |  |  |  |  | n-1  |
    // +------+---+---+---+--+--+--+--+--+--+------+
    // | head |   |   |   |  |  |  |  |  |  | tail |
    // +------+---+---+---+--+--+--+--+--+--+------+
    int capacity = 0;
    int count = 0;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        queue.reserve(k);
        head = 0;
        tail = k-1;
        capacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        queue[head] = value;
        head = (head + 1) % capacity;
        count++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        queue[tail] = value;
        tail = (tail - 1 + capacity) % capacity;
        count++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        head = (head - 1 + capacity) % capacity;
        count--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        tail = (tail + 1) % capacity;
        count--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(head - 1 + capacity) % capacity];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(tail + 1) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {

    MyCircularDeque *obj = new MyCircularDeque(3);
    //["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]
    //[[3],[1],[2],[3],[4],[],[],[],[4],[]]
    cout << obj->insertFront(1)<< endl;
    cout << obj->insertFront(2)<< endl;
    cout << obj->insertFront(3)<< endl;
    cout << obj->insertFront(4)<< endl;
    cout <<  obj->getRear() <<endl;

    return 0;
}