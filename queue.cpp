#include<iostream>
using namespace std;
class Queue {
private:
    int *arr;
    int capacity;
    int front;
    int rear;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];   
        this->front = 0;
        this->rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int data);
    void dequeue();
    void peek();
    void getFront();
    void getRear();
    bool isFull();
    bool isEmpty();
    void isSize();
    void display();
};

void Queue::enqueue(int data) {
    if (isFull()) {
        cout << "Queue is Full." << endl;
        return;
    }
    arr[++rear] = data;
    cout << "Inserted: " << data << endl;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } 
    else {
        cout << "Deleted: " << arr[front++] << endl;

        
    }
}

void Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is Empty." << endl;
        return;
    }
    cout << "Peek: " << arr[front] << endl;
}

void Queue::getFront() {
    if (isEmpty()) {
        cout << "Queue is Empty." << endl;
        return;
    }
    cout << "Front: " << arr[front] << endl;
}

void Queue::getRear() {
    if (isEmpty()) {
        cout << "Queue is Empty." << endl;
        return;
    }
    cout << "Rear: " << arr[rear] << endl;
}

bool Queue::isEmpty() {
    return rear < front;
}

bool Queue::isFull() {
    return rear == capacity - 1;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Queue::isSize() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } 
    else {
        cout << "Size of Queue: " << rear - front + 1 << endl;
    }
}

int main(){
    Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.display();
    queue.dequeue();
    queue.peek();
    queue.getFront();
    queue.getRear();
    cout<<queue.isFull()<<endl;
    cout<<queue.isEmpty()<<endl;
    queue.isSize();
    return 0;
}