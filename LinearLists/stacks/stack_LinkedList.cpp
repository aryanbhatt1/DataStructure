//
// Created by aryan on 18-11-2021.
//
#include <iostream>
using namespace std;

class stackNode{
public:
    int data;
    stackNode* next;
};

stackNode* newNode(int data){
    stackNode* StackNode = new stackNode();
    StackNode->data = data;
    StackNode->next = nullptr;
    return StackNode;
}


int main(){

}