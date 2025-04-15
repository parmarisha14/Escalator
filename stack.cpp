#include<iostream>
using namespace std;

class Stack{
private:
    int *arr;
    int capacity;
    int top;
public:
    Stack(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack(){
        delete[] arr;
    }

    void push(int data);
    void pop();
    void peek();
    bool isEmpty();
    bool isFull();
    void size();
    void display();
};

void Stack::push(int data){
    if(isFull()){
        cout << "Stack is overflow"<<endl;
        return;
    } else {
        arr[++top] = data;
        cout << "Push the Data " << data << endl;
    }
}

void Stack::pop(){
    if(isEmpty()){
        cout << "Stack is Empty"<<endl;
        return;
    } else {
        cout << "Pop the data:" << arr[top--] << endl;
    }
}

void Stack::peek(){
    if(isEmpty()){
        cout << "Stack is Empty"<<endl;
        return;
    }
    cout << "Top element is: " << arr[top] << endl;
}

bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == capacity - 1;
}

void Stack::size(){
    cout << "Stack total amount of: " << top + 1 << endl;
}

void Stack::display(){
    if(isEmpty()){
        cout << "Stack is Empty." << endl;
        return;
    }
    cout << "Stack data: ";
    for(int i = top; i >= 0; i--){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.display();
    stack.pop();
    stack.peek();
    cout<<"Stack is Empty or Not:"<<stack.isEmpty()<<endl;
    cout<<"Stack is Full or Not:"<<stack.isFull()<<endl;
    stack.size();

    return 0;
}
