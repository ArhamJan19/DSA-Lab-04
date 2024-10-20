#include <iostream>
#include <sstream>
using namespace std;


int getValidIntInput(const string& prompt) {
    string input;
    int value;
    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            return value;
        }
        cout << "\nInvalid input, please enter a valid number.\n";
    }
}


template <typename T>
class LinearQueue {
private:
    T* queueArray;
    int front;
    int rear;
    int capacity;

public:
    LinearQueue(int size) {
        capacity = size;
        queueArray = new T[capacity];
        front = -1;
        rear = -1;
    }

    ~LinearQueue() {
        delete[] queueArray;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void insert(T value) {
        if (isFull()) {
            cout << "\nQueue is full. Cannot insert new elements.\n";
            return;
        }

        if (front == -1) front = 0;
        queueArray[++rear] = value;
        cout << "\nInserted: " << value << endl;
    }

    void remove() {
        if (isEmpty()) {
            cout << "\nQueue is empty. No elements to remove.\n";
            return;
        }

        cout << "\nRemoved: " << queueArray[front++] << endl;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "\nQueue is empty.\n";
        } else {
            cout << "\nQueue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queueArray[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size = getValidIntInput("Enter the size of the queue: ");
    LinearQueue<int> queue(size);

    bool running = true;
    while (running) {
        cout << "\n1. Insert";
        cout << "\n2. Remove";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        int choice = getValidIntInput("\nEnter your choice: ");

        switch (choice) {
        case 1: {
            if (!queue.isFull()) {
                int value = getValidIntInput("Enter the value to insert: ");
                queue.insert(value);
            }
            break;
        }

        case 2:
            queue.remove();
            break;

        case 3:
            queue.displayQueue();
            break;

        case 4:
            running = false;
            cout << "\nExiting the program.\n";
            break;

        default:
            cout << "\nInvalid choice. Please select a valid option.\n";
            break;
        }
    }

    return 0;
}
