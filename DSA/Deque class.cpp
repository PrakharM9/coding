#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Deque class using a doubly linked list
class Deque {
private:
    Node* front; // Pointer to the front of the deque
    Node* rear;  // Pointer to the rear of the deque
    int count;   // Count of elements in the deque

public:
    Deque() : front(nullptr), rear(nullptr), count(0) {}

    // Push at the front of the deque
    void pushFront(int value) {
        Node* newNode = new Node(value);
        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        count++;
    }

    // Push at the rear of the deque
    void pushBack(int value) {
        Node* newNode = new Node(value);
        if (!rear) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    // Pop from the front of the deque
    void popFront() {
        if (!front) {
            cout << "Deque is empty, cannot pop from front." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }
        delete temp;
        count--;
    }

    // Pop from the rear of the deque
    void popBack() {
        if (!rear) {
            cout << "Deque is empty, cannot pop from back." << endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }
        delete temp;
        count--;
    }

    // Get the element at the front
    int topFront() {
        if (!front) {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return front->data;
    }

    // Get the element at the rear
    int topBack() {
        if (!rear) {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return rear->data;
    }

    // Get the size of the deque
    int size() {
        return count;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    Deque dq;

    // Test operations
    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    cout << "Front element: " << dq.topFront() << endl; // Output: 5
    cout << "Rear element: " << dq.topBack() << endl;   // Output: 20

    dq.popFront();
    cout << "Front element after popFront: " << dq.topFront() << endl; // Output: 10

    dq.popBack();
    cout << "Rear element after popBack: " << dq.topBack() << endl;   // Output: 10

    cout << "Size of deque: " << dq.size() << endl; // Output: 1

    return 0;
}
