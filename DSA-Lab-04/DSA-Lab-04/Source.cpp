#include<iostream>
using namespace std;

template<class Type>
class Queue {
private:
	int size
		int front;
	int rear;
	Type* queue;


public:
	Queue(int size) {
		front = -1;
		rear = -1;
		queue = new Type[size];
	}
	~Queue() {
		delete[] queue;
	}
	void getQueue() {
		for (int i = 0; i <= rear; i++) {
			cout << "Element at " << i << " is " << queue[i] << endl;
		}
	}
	bool isFull() {
		return (rear == 9);
	}
	bool isEmpty() {
		return(front == -1 && rear == -1);
	}
	void insert(Type item) {
		if (isFull()) {
			cout << endl << "Queue is Full" << endl;
		}
		else {
			if (isEmpty()) {
				rear++;
				front++;
				queue[rear] = item;
				cout << item << " inserted" << endl;
			}
			else {
				rear++;
				queue[rear] = item;
				cout << item << " inserted" << endl;
			}
		}
	}
	void remove(Type& item) {
		if (isEmpty()) {
			cout << endl << "The Queue is empty" << endl;
		}
		else {
			if (front == 0 && rear == 0) {
				cout << "item " << queue[front] << " removed" << endl;
				item = queue[front];
				front--;
				rear--;
			}
			else if (front == rear) {
				cout << "item " << queue[front] << " removed" << endl;
				item = queue[front];
				front = -1;
				rear = -1;
			}
			else {
				cout << "item " << queue[front] << " removed" << endl;
				item = queue[front];
				front++;
			}

		}
	}
};

void Menu() {
	cout << "1. Insert into the Queue." << endl;
	cout << "2. Delete from the Queue." << endl;
	cout << "3. Print the Queue." << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your Choice : ";
}

int main() {
	int choice;
	Queue<int>* queue = new Queue<int>(10);

	do {
		Menu();
		cin >> choice;

		if (choice == 1) {
			int item;
			cout << "Enter the item you want to enter:  ";
			cin >> item;
			queue->insert(item);
		}
		else if (choice == 2) {
			int item;
			queue->remove(item);

		}
	} while (choice != 1 || choice != 2 || choice != 3);

		
	return 0;
}