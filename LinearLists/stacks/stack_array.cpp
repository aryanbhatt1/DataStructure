//
// Created by aryan on 18-11-2021.
//
#include <iostream>
#define MAX 100
using namespace std;

class Stack {
    int top;
public:
    int a[MAX];
    Stack() {
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x){
    if (top >= (MAX-1)){
        cout<<"Stack Overflow!!"<<endl;
        return false;
    }
    else{
        a[++top] = x;
        cout<<x<<" pushed into Stack"<<endl;
        return true;
    }
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack Underflow!!"<<endl;
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if (top<0){
        cout<<"Stack is empty!!"<<endl;
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top<0);
}

int main(){
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.isEmpty()){
        cout<<s.peek()<<"\n";
        s.pop();
    }
    return 0;
}