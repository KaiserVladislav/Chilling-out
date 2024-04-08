#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> queue;
    int max_size;
    int front;
    int rear;

public:
    Queue(int size) : max_size(size), front(0), rear(0) {
        queue.resize(max_size);
    }

    void enqueue(int value) {
        if ((rear + 1) % max_size == front) {
            cout << "Queue is full. Cannot insert: " << value << endl;
            return;
        }
        queue[rear] = value;
        rear = (rear + 1) % max_size;
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is empty. Cannot remove." << endl;
            return;
        }
        front = (front + 1) % max_size;
    }

    int getFront() {
        if (front == rear) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[front];
    }

    int size() {
        return (rear - front + max_size) % max_size;
    }

    bool isEmpty() {
        return front == rear;
    }

    void display() {
        if (front == rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % max_size;
        } while (i != rear);
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    int choice;
    int value;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Get Front\n4. Size\n5. Display\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front value: " << q.getFront() << endl;
                break;
            case 4:
                cout << "Size of the queue: " << q.size() << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 6);

    return 0;
}