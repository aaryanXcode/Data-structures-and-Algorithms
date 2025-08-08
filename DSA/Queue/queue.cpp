#include <bits/stdc++.h>
using namespace std;

// FIFO - First In First Out
class queueUsingArray {
    int* data;
    int capacity;
    int nextElement; // index to pop
    int tempidx;     // index to push
    int currentSize;

public:
    queueUsingArray() {
        data = new int[4];
        capacity = 4;
        nextElement = 0;
        tempidx = 0;
        currentSize = 0;
    }

    void push(int element) {
        if (currentSize == capacity) {
            // Resize and copy in correct order
            int* newData = new int[2 * capacity];
            for (int i = 0; i < currentSize; i++) {
                newData[i] = data[(nextElement + i) % capacity];
            }

            delete[] data;
            data = newData;
            nextElement = 0;
            tempidx = currentSize;
            capacity *= 2;
        }

        data[tempidx] = element;
        tempidx = (tempidx + 1) % capacity;
        currentSize++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        nextElement = (nextElement + 1) % capacity;
        currentSize--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return data[nextElement];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    int size() {
        return currentSize;
    }

    ~queueUsingArray() {
        delete[] data;
    }
};

int main() {
    queueUsingArray q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    
    cout << endl;

    cout<<q.front()<<endl;
}
