//
// Created by aryan on 18-11-2021.
//
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node* head;

void insertFirst(int data){
    auto *newNode =  (struct Node*)malloc(sizeof (struct Node));
    if(newNode == nullptr){
        cout<<"Overflow"<<endl;
    }
    else{
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
}

void insertMiddle(int data, int pos){
    auto *newNode = (struct Node*)malloc(sizeof (struct Node));
    struct Node *temp;
    if(newNode == nullptr){
        cout<<"Overflow"<<endl;
    }
    else{
        newNode->data = data;
        temp = head;
        for(int i=1; i<pos-1; i++){
            temp= temp->next;
            if(temp== nullptr){
                cout<<"Can Insert"<<endl;
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertLast(int data){
    auto *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;
    if(newNode == nullptr){
        cout<<"Overflow"<<endl;
    }
    else{
        newNode->data = data;
        if(head == nullptr){
            newNode->next = nullptr;
            head = newNode;
        }
        else {
            temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }
    }
}

void countLinkedList(){
    struct Node *temp;
    temp = head;
    int count = 0;
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    cout<<count<<endl;
}

void deleteFirst(){
    if (head == nullptr){
        cout<<"Empty List, nothing to delete"<<endl;
    }
    head = head->next;
}

void deleteMiddle(int pos){
    struct Node *temp;
    struct Node *temp2;
    temp = head;
    for(int i=0; i<pos-1; i++){
        temp2 = temp;
        temp = temp->next;
        if (temp == nullptr) {
            cout << "Can't Delete" << endl;
            return;
        }
    }
    temp2->next = temp->next;
    free(temp);
}

void deleteLast(){
    struct Node *temp;
    struct Node *LastNode;
    if (head == nullptr){
        cout<<"Empty List, nothing to delete"<<endl;
    }
    else if (head->next == nullptr){
        head = nullptr;
        free(head);
    }
    else {
        temp = head;
        while(temp->next != nullptr){
            LastNode = temp;
            temp = temp->next;
        }
        LastNode->next = nullptr;
        free(temp);
    }
}
void printLinkedList(){
    struct Node *temp;
    temp=head;
    if(temp == nullptr){
        cout<<"Empty List"<<endl;
    }
    else{
        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp= temp->next;
        }
    }
    cout<<"null"<<endl;
}

int main(){
    insertFirst(5);
    printLinkedList();
    insertLast(8);
    printLinkedList();
    insertLast(10);
    printLinkedList();
    insertMiddle(4,2);
    printLinkedList();
    countLinkedList();
    insertMiddle(9,4);
    printLinkedList();
    return 0;
}